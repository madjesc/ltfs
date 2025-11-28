#pragma once
/**
 * Message header definition for KMI SIMPLE module
 * range: 15550 - 15599
 */

#define D15500 "Simple plug-in initialized."
#define D15501 "Simple plug-in uninitialized."
#define E15502 "Encryption key format violation (%s): %s."
#define E15503 "Cannot find data key."
#define E15504 "Option parsing for the key manager interface backend failed (%d)."
#define E15505 "Invalid sequence error (%d,%d): %s."
#define E15506 "Failed to parse data key and/or data key identifier."
#define E15507 "Cannot find data key of the data key identifier."

#define I15508 "Key manager interface simple plug-in options:\n" \
  "    -o kmi_dk=<DK>\n" \
  "                              Data key\n" \
  "    -o kmi_dki=<DKi>\n" \
  "                              Data key identifier\n" \
  "    -o kmi_dk_for_format=<DK>\n" \
  "                              Data key to format a cartridge\n" \
  "    -o kmi_dki_for_format=<DKi>\n" \
  "                              Data key identifier to format a cartridge\n" \
  "    -o kmi_dk_list=<DK>:<DKi>/<DK>:<DKi>/.../<DK>:<DKi>\n" \
  "                              Data key and data key identifier pairs' list\n\n."
