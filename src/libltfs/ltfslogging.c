/*
**
**  OO_Copyright_BEGIN
**
**
**  Copyright 2010, 2025 IBM Corp. All rights reserved.
**
**  Redistribution and use in source and binary forms, with or without
**   modification, are permitted provided that the following conditions
**  are met:
**  1. Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**  2. Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**  documentation and/or other materials provided with the distribution.
**  3. Neither the name of the copyright holder nor the names of its
**     contributors may be used to endorse or promote products derived from
**     this software without specific prior written permission.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
**  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
**  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
**  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
**  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
**  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
**  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
**  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
**  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
**  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
**  POSSIBILITY OF SUCH DAMAGE.
**
**
**  OO_Copyright_END
*/

/*************************************************************************************
 ** FILE NAME:       ltfslogging.c
 **
 ** DESCRIPTION:     Routines for logging via syslog and stderr. (LTFS messages)
 **
 ** AUTHORS:         Brian Biskeborn
 **                  IBM Almaden Research Center
 **                  bbiskebo@us.ibm.com
 **
 *************************************************************************************
 */

#include "arch/ltfs_arch_ops.h"
#include "ltfs_locking_old.h"
#include "ltfs_thread.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unicode/ucnv_err.h>
#ifdef mingw_PLATFORM
#	include "arch/win/win_util.h"
#	include <windows.h>
#endif
#include <stdarg.h>
#ifndef mingw_PLATFORM
#	include <syslog.h>
#endif

#ifdef __APPLE_MAKEFILE__
#	include <ICU/unicode/uclean.h>
#	include <ICU/unicode/ucnv.h>
#	include <ICU/unicode/udata.h>
#	include <ICU/unicode/utypes.h>
#else
#	include <unicode/putil.h>
#	include <unicode/uclean.h>
#	include <unicode/ucnv.h>
#	include <unicode/udata.h>
#	include <unicode/ures.h>
#	include <unicode/utypes.h>
#endif
#ifdef mingw_PLATFORM
#	include "arch/win/winlog.h"
#	include <fcntl.h>
#	include <sys/stat.h>
#	include <sys/types.h>
#	include <unistd.h>
#else
#	include <dlfcn.h>
#	include <sys/types.h>
#endif

#include "libltfs/ltfslogging.h"

/* Some hard-coded message bits. */
#define MSG_PREFIX_POSIX_TID "%016llx LTFS%s "
#define MSG_PREFIX_TID "%lx LTFS%s "
#define MSG_PREFIX "LTFS%s "
#define MSG_FALLBACK "(could not generate message)"

/* Syslog levels corresponding to the LTFS logging levels defined in libltfs/ltfslogging.h. */
static int syslog_levels[] = {
	LOG_ERR,		 /* LTFS_ERR    */
	LOG_WARNING, /* LTFS_WARN   */
	LOG_INFO,		 /* LTFS_INFO   */
	LOG_DEBUG,	 /* LTFS_DEBUG  */
	LOG_DEBUG,	 /* LTFS_DEBUG1 */
	LOG_DEBUG,	 /* LTFS_DEBUG2 */
	LOG_DEBUG,	 /* LTFS_DEBUG3 */
	LOG_DEBUG,	 /* LTFS_TRACE  */
};

int ltfs_log_level = LTFS_INFO;
int ltfs_syslog_level = LTFS_INFO;
bool ltfs_print_thread_id = false;
static bool ltfs_use_syslog = false;

extern const char messages_dat[];

/* Static output buffer: needed to avoid allocating memory on error. */
static ltfs_mutex_t output_lock;
static UResourceBundle *messages = NULL;
static UConverter *conv = NULL;

int ltfsprintf_init(int log_level, bool use_syslog, bool print_thread_id)
{
	int ret = 0;
	UErrorCode err = U_ZERO_ERROR;
	udata_setAppData("messages", messages_dat, &err);
	if (U_FAILURE(err)) {
		fprintf(stderr, "LTFS11287E Cannot load messages: failed to register message data (%d)\n", err);
		return -1;
	}

	messages = ures_open("messages", NULL, &err);
	if (U_FAILURE(err)) {
		ltfsmsg(LTFS_DEBUG, 11286E, err);
		return -err;
	}
	conv = ucnv_open(NULL, &err);
	if (U_FAILURE(err)) {
		ltfsmsg(LTFS_DEBUG, 9008E, err);
		return -err;
	}

	/* Open converter for generating output in the system locale. */
	ret = ltfs_mutex_init(&output_lock);
	if (ret > 0) {
		fprintf(stderr, "LTFS10002E Could not initialize mutex (%d)\n", ret);
		return -ret;
	}

	ltfs_log_level = log_level;
	ltfs_use_syslog = use_syslog;
	ltfs_print_thread_id = print_thread_id;
	return ret;
}

/* Shut down the logging and error reporting framework. */
void ltfsprintf_finish()
{
	ures_close(messages);
	ucnv_close(conv);
	ltfs_mutex_destroy(&output_lock);
	u_cleanup();
}

/* Update ltfs_log_level */
int ltfsprintf_set_log_level(int log_level)
{
	if (log_level < LTFS_ERR) {
		fprintf(stderr, "LTFS11318W Unknown log level (%d), forced the level to (%d)\n", log_level, LTFS_ERR);
		log_level = LTFS_ERR;
	} else if (log_level > LTFS_TRACE) {
		fprintf(stderr, "LTFS11318W Unknown log level (%d), forced the level to (%d)\n", log_level, LTFS_TRACE);
		log_level = LTFS_TRACE;
	} else {
		ltfs_log_level = log_level;
	}
	return 0;
}

/* Print a formatted message in the current system locale. */
int ltfsmsg_internal(bool print_id, int level, char **msg_out, const char *_id, ...)
{
	va_list argp;
	int ret = 0;
	UErrorCode err = U_ZERO_ERROR;
	UResourceBundle *res_ctxt = NULL, *res_msg = NULL;
	char *uchar_bytes = NULL;
	size_t byte_count = 0;
	int32_t msg_len = 0, tid = 0;
	const UChar *msg_str = NULL;

	ures_resetIterator(messages);
	while (ures_hasNext(messages) != false) {
		res_ctxt = ures_getNextResource(messages, res_ctxt, &err);
		if (U_FAILURE(err) || res_ctxt == NULL) continue;
		res_msg = ures_getByKey(res_ctxt, _id, res_msg, &err);
		if (U_SUCCESS(err) && res_msg != NULL) break;
		err = U_ZERO_ERROR;
	}
	if (res_msg == NULL || U_FAILURE(err)) {
		fprintf(stderr, MSG_FALLBACK "\n");
		ret = -1;
		goto close;
	}

	msg_len = ures_getSize(res_msg);
	msg_str = ures_getString(res_msg, &msg_len, &err);
	if (U_FAILURE(err)) {
		ret = -1;
		goto close;
	}

	byte_count = UCNV_GET_MAX_BYTES_FOR_STRING(msg_len, ucnv_getMaxCharSize(conv));
	uchar_bytes = malloc(sizeof(char) * byte_count);
	byte_count = ucnv_fromUChars(conv, uchar_bytes, byte_count, msg_str, msg_len, &err);
	if (U_FAILURE(err)) {
		ret = -1;
		goto close;
	}

	ltfs_mutex_lock(&output_lock);
	tid = ltfs_get_thread_id();
	if (ltfs_print_thread_id)
		fprintf(stderr, MSG_PREFIX_TID, (unsigned long)tid, _id);
	else
		fprintf(stderr, MSG_PREFIX, _id);

	va_start(argp, _id);
	vfprintf(stderr, uchar_bytes, argp);
	fprintf(stderr, "\n");
	va_end(argp);

	if (level <= ltfs_syslog_level && ltfs_use_syslog) {
		va_start(argp, _id);
		if (level <= LTFS_ERR)
			vsyslog(syslog_levels[LTFS_ERR], uchar_bytes, argp);
		else if (level >= LTFS_TRACE)
			vsyslog(syslog_levels[LTFS_TRACE], uchar_bytes, argp);
		else
			vsyslog(syslog_levels[level], uchar_bytes, argp);
		va_end(argp);
	}

	if (msg_out) {
		va_start(argp, _id);
		arch_vsprintf(*msg_out, NULL, uchar_bytes, argp);
		va_end(argp);
	}

	ltfs_mutex_unlock(&output_lock);

	// #ifdef ENABLE_SNMP
	//   if (is_snmp_enabled()) {
	//     if (is_snmp_trapid(id) == true) {
	//       /* Send a trap of Info (id and pos+1) */
	//       char *pos;
	//       va_start(argp, _id);
	//       arch_vsprintf(msg_buf, sizeof(msg_buf), output_buf, argp);
	//       va_end(argp);
	//       pos = strstr(msg_buf, " ");
	//       send_ltfsInfoTrap(pos + 1);
	//     }
	//   }
	// #endif

close:
	if (res_msg != NULL) ures_close(res_msg);
	if (res_ctxt != NULL) ures_close(res_ctxt);
	if (uchar_bytes != NULL) free(uchar_bytes);
	return ret;
}
