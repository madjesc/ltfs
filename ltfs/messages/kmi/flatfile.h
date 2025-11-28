#pragma once
/**
 * Message header definition for KMI FLATFILE module
 * range: 15550 - 15599
 */

// Message IDs 15500-15009 are reserved for the crypto direct plugins.
// DO NOT add messages with those IDs to this file.
//
#define D15550 "Flat File plug-in initialized."
#define D15551 "Flat File plug-in uninitialized."
#define E15552 "Flat File plug-in failed to parse options."
#define E15553 "Flat File plug-in failed to open the file (%s, %d)."
#define E15554 "Flat File plug-in detected key format violation."

// for LTFS specific format
#define E15562 "Encryption key format violation (%s): %s."
#define E15563 "Cannot find data key."
#define E15564 "Option parsing for the key manager interface backend failed (%d)."
#define E15565 "Invalid sequence error (%d,%d): %s."
#define E15566 "Failed to parse data key and/or data key identifier."
#define E15567 "Cannot find data key of the data key identifier."
#define I15568 "Key manager interface flatfile plug-in options:\n" \
  "    -o kmi_dki_for_format=<DKi>\n" \
  "                              Data key identifier to format a cartridge\n" \
  "    -o kmi_dk_list=FILE\n" \
  "                              Data key and data key identifier pairs' list file\n\n."
