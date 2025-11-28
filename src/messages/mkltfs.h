#pragma once
/**
 * Message header definition for MKLTFS binary
 * range: 15000 - 15499
 */
#define I15000 "Starting mkltfs, %s version %s, log level %d."
#define E15001 "Cannot allocate LTFS volume structure."
#define E15002 "Option validation failed."
#define I15003 "Formatting device \'%s\'."
#define I15004 "LTFS volume blocksize: %lu."
#define I15005 "Index partition placement policy: %s."
#define D15006 "Opening the device."
#define D15007 "Device opened."
#define E15008 "Cannot open backend \'%s\'."
#define E15009 "Cannot open device \'%s\' (%d)."
#define I15010 "Creating data partition %c on SCSI partition %d."
#define I15011 "Creating index partition %c on SCSI partition %d."
#define E15012 "Failed to format the medium."
#define I15013 "Volume UUID is: %s."
#define E15014 "Cannot set policy override flag in the index (%d)."
#define E15015 "Cannot parse data placement rules (%d)."
//unused #define E15016 "Cannot create a backup of the policy rules (%d)."
#define I15019 "Volume capacity is %llu GB."
#define D15020 "Closing the device."
#define W15021 "Cannot unload backend."
#define D15022 "Device closed."
#define I15023 "Formatting failed."
#define I15024 "Medium formatted successfully."
#define D15025 "Validating command line options."
#define E15026 "Device name must use the \'%s\' option."
//unused #define E15027 "Block size must be greater than zero."
#define E15028 "Block size must be at least %d."
#define E15029 "Tape serial must be 6 characters."
#define E15030 "Tape serial must contain only ASCII digits and capital letters."
#define E15031 "Volume name must conform to file name rules."
//unused #define E15032 "Data placement rules contain invalid characters."
//unused #define E15033 "Data placement rules are too long."
#define E15034 "Cannot format data placement rules (%d)."
//unused #define E15035 "Cannot parse data placement rules (%d)."
//unused #define E15036 "Cannot specify name rules with a zero file size."
#define D15037 "Command line options are valid."
#define E15038 "Failed to unformat the medium."
#define I15039 "Unformatting failed."
#define I15040 "Medium unformatted successfully."
#define I15041 "Launched by \"%s\"."
#define I15042 "%s."
#define I15043 "GCC version is %s."
#define E15044 "Cannot set up tape device."
#define E15045 "Formatting was canceled by the user."
#define E15046 "Unformatting was canceled by the user."
#define E15047 "Medium is already formatted (%d)."
#define I15048 "Need to specify -f or --force option to format this medium."
#define I15049 "Checking the medium (%s)."
#define E15050 "Cannot open key manager interface backend \'%s\'."
#define W15051 "Cannot unload key manager interface backend."
#define E15052 "Could not initialize the key manager interface plug-in. \'%s\' (%d)."
#define E15053 "Key manager interface backend option parsing failed."
#define E15054 "Tape backend option parsing failed."
#define E15055 "Unknown option '%s %s'."
#define E15056 "Failed to decrypt the medium."
#define I15057 "Need to specify the correct data key or -f option to format this medium."
#define E15058 "Cannot set the tape attribute: %s."
#define I15059 "%s version %s."
#define E15060 "Index criteria update is not allowed on this medium."
#define E15061 "Failed to format the medium due to WORM error."
#define E15062 "Failed to unformat the medium due to WORM error."

#define I15400 "Usage: %s <options>" \
  "Available options are:" \
  "  -d, --device=<name>       Tape device (required)" \
  "  -s, --tape-serial=<id>    Tape serial number (6 alphanumeric ASCII characters)" \
  "  -n, --volume-name=<name>  Tape volume name (empty by default)" \
  "  -r, --rules=<rules>       Rules for choosing files to write to the index partition.\n" \
  "                            The syntax of the rule argument is:\n" \
  "                                size=1M\n" \
  "                                size=1M/name=pattern\n" \
  "                                size=1M/name=pattern1:pattern2:pattern3\n" \
  "                            A file is written to the index partition if it is no larger\n" \
  "                            than the given size AND matches at least one of the name" \
  "                            patterns (if specified). The size argument accepts K, M, and G\n" \
  "                            suffixes. Name patterns might contain the special characters\n" \
  "                            '?' (match any single character) and '*' (match zero or more\n" \
  "                            characters)" \
  "      --no-override         Disallow mount-time data placement policy changes" \
  "  -q, --quiet               Suppress progress information and general messages" \
  "  -t, --trace               Enable function call tracing" \
  "  -h, --help                This help" \
  "Usage example:" \
  "  %s --device=%s --rules=\"%s\"" \
  "  -p, --advanced-help       Full help, including advanced options" \
  "  -i, --config=<file>       Use the specified configuration file (default: %s)" \
  "  -e, --backend=<name>      Use the specified tape device backend (default: %s)" \
  "  -b, --blocksize=<num>     Set the LTFS record size (default: %d)" \
  "  -c, --no-compression      Disable compression on the volume" \
  "  -x, --fulltrace           Enable full function call tracing (slow)" \
  "  -w, --wipe                Restore the LTFS medium to an unpartitioned medium (format to a legacy scratch medium)" \
  "  -k, --keep-capacity       Keep the tape medium's total capacity proportion" \
  "  -f, --force               Force to format medium" \
  "      --kmi-backend=<name>  Use the specified key manager interface backend (default: %s)" \
  "      --syslogtrace               Enable diagnostic output to stderr and syslog" \
  "  -V, --version             Version information" \
  "      --long-wipe           Unformat the medium and erase any data on the tape by overwriting special data pattern.\n" \
  "                            This operation takes over 3 hours. Once you start, you cannot interrupt it" \
  "      --destructive         Use destructive format/unformat. This operation takes longer time\n" \
  "                            in the LTO9 drive or later because of the media optimization procedure"
