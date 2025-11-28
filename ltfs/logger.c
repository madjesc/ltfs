#include "logger.h"
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/syslog.h>
#include <time.h>

struct {
  enum LtfsLogLevel max_level;
  bool show_time;
  bool show_thread_id;
} LtfsLogger = {.max_level = ERROR};

void LoggerShowTime(void) { LtfsLogger.show_time = true; }
void LoggerShowThread(void) { LtfsLogger.show_thread_id = true; }

void ltfslog(enum LtfsLogLevel level, const char *restrict message,
                       ...) {
  if (level > LtfsLogger.max_level)
    return;
  int syslevel = 0;
  time_t now = time(NULL);
  pthread_t thid = pthread_self();
  char timestr[20];

  switch (level) {
  case ERROR:
    syslevel = LOG_ERR;
    break;
  case INFO:
    syslevel = LOG_INFO;
    break;
  case WARNING:
    syslevel = LOG_WARNING;
    break;
  case DEBUG:
    syslevel = LOG_DEBUG;
    break;
  default:
    syslevel = LOG_NOTICE;
    break;
  }

  if (LtfsLogger.show_time) {
    strftime(timestr, 20, "%Y-%m-%dT%H:%M:%S", localtime(&now));
    fputs(timestr, stderr);
    fputc(' ', stderr);
  }
  if (LtfsLogger.show_thread_id)
    fprintf(stderr, "%lx ", thid);
  va_list args;
  va_start(args, message);
  vfprintf(stderr, message, args);
  vsyslog(syslevel, message, args);
  va_end(args);
  fputc('\n', stderr);
}
