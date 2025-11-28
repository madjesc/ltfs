#pragma once
/**
 * Message header definition for LTFSCK binary
 * range: 16000 - 16499
 */
#define I16000 "Starting ltfsck, %s version %s, log level %d."
#define E16001 "Cannot allocate LTFS volume structure."
#define E16002 "Option validation failed."
#define E16003 "Must provide search criteria using -g."
#define E16004 "Unexpected condition: str_gen is not specified."
#define E16005 "Invalid generation number %s."
#define I16006 "Rolling back to generation %d."
// #define E16007 "Invalid time string %s."
// #define D16008 "Specified time is %04d-%02d-%02d %02d:%02d:%02d.%09ld %s."
#define E16009 "Must provide device name."
#define E16010 "Cannot load backend \'%s\' (%d)."
#define E16011 "Cannot open device \'%s\'."
// #define E16012 "Cannot load medium."
// #define E16013 "Cannot take the device lock (%d)."
#define I16014 "Checking LTFS file system on \'%s\'."
#define I16015 "Rolling back LTFS file system on \'%s\'."
#define E16016 "Invalid search mode."
#define I16017 "Verify rollback point on \'%s\'."
#define I16018 "Listing LTFS file system rollback points on \'%s\'."
#define E16019 "Invalid operation mode."
#define W16020 "Failed to close the device (%d)."
#define E16021 "Volume is inconsistent and was not corrected."
#define I16022 "Volume is consistent."
#define I16023 "LTFS volume information:."
#define I16024 "Volser (bar code) : %s."
#define I16025 "Volume UUID     : %s."
#define I16026 "Format time     : %04d-%02d-%02d %02d:%02d:%02d.%09ld %s."
#define I16027 "Block size      : %lu."
#define I16028 "Compression     : %s."
#define I16029 "Index partition : ID = %c, SCSI Partition = %u."
#define I16030 "Data partition  : ID = %c, SCSI Partition = %u."
#define I16031 "Data placement policy information:."
#define I16032 "Size threshold : %llu."
#define I16033 "Name pattern   : %s."
#define I16034 "Policy update  : %s."
// #define E16035 "Cannot traverse indexes: failed to seek EOD on partition %c (%d)."
// #define E16036 "Cannot traverse indexes: failed to space back 1 file mark (%d)."
// #define E16037 "Cannot traverse indexes: failed to space forward 1 file mark (%d)."
// #define I16038 "Partition %c ends in a valid index, but no trailing file mark was found. Closing the partition with a file mark."
// #define D16039 "Partition %c ends in a file mark."
// #define I16040 "Partition %c ends in a valid index, but no trailing file mark was found."
// #define D16041 "Partition %c ends in a valid index."
// #define E16042 "Cannot traverse indexes: callback function failed (%d)."
// #define I16043 "Partition %c does not end in a valid index."
// #define E16044 "Cannot traverse indexes: failed to space back file marks (%d)."
#define D16045 "Erasing history from (%c, %llu)."
#define D16046 "Rolling back %s: (%c, %llu)."
// #define E16047 "Cannot read volume: failed to load the tape (%d)."
// #define E16048 "Cannot read volume: failed to read the partition labels (%d)."
// #define E16049 "Cannot read volume: failed to set compression (%d)."
#define D16050 "Erase history: spacing to end of index."
#define E16051 "Cannot erase history: failed to space forward 1 file mark (%d)."
#define D16052 "Erase history: spacing back and writing a file mark."
#define E16053 "Cannot erase history: failed to space back 1 file mark (%d)."
#define E16054 "Cannot erase history: failed to write a file mark (%d)."
#define E16055 "Cannot roll back the data partition: failed to erase history (%d)."
#define E16056 "Cannot roll back the data partition: failed to write an index (%d)."
#define E16057 "Cannot roll back: the medium is read-only."
#define I16058 "Rolling back from the index partition."
#define E16059 "Cannot roll back the index partition: failed to erase history (%d)."
#define E16060 "Cannot roll back the index partition: failed to write an index (%d)."
#define E16061 "Cannot roll back: invalid partition ID %c."
#define I16062 "Roll back from the data partition."
#define I16063 "Specified rollback point is the current index. The volume is consistent. No operation is required."
// #define I16064 "Specified rollback point is the current index, but there are extra blocks on the medium."
// #define I16065 "Restoring volume consistency based on the following index."
// #define I16066 "At least one index is not at the end of its partition."
#define I16067 "Rolling back based on the following index chain."
#define E16068 "Cannot roll back: found 2 or more target indexes in one partition (%d)."
// #define E16069 "Cannot roll back: found 3 or more target indexes."
#define E16070 "Cannot roll back: failed to load the volume (%d)."
#define E16071 "Cannot roll back: failed to traverse the index partition (%d)."
#define E16072 "Cannot roll back: failed to traverse the data partition (%d)."
#define E16073 "Cannot roll back: failed to find indexes."
#define E16074 "Cannot list rollback points: failed to load the volume (%d)."
#define E16075 "Cannot list rollback points: failed to traverse the index partition (%d)."
#define E16076 "Cannot list rollback points: failed to traverse the data partition (%d)."
// #define I16077 "Valid indexes:."
// #define I16078 "No indexes found."
#define E16079 "Cannot roll back: failed to save index partition append position (%d)."
#define E16080 "Cannot check volume (%d)."
#define D16081 "Latest index generation is %d (%c, %llu)."
#define I16082 "Saving latest index to data partition to save history."
#define I16083 "List indexes in forward direction strategy."
#define I16084 "List indexes in backward direction strategy."
#define E16085 "Unexpected traverse strategy."
#define I16086 "Volume is rolled back successfully."
#define E16087 "Volume is inconsistent. Try to recover consistency with ltfsck first."
#define I16088 "Launched by \"%s\"."
#define I16089 "%s."
#define I16090 "GCC version is %s."
#define E16091 "Cannot recover missing EOD (%d)."
#define E16092 "Cannot set up tape drive (%s)."
#define E16093 "Cannot recover the cartridge with ltfsck."
#define E16094 "CM in the cartridge might be corrupted. Try to run ltfs with the \"-o force_mount_no_eod\" option."
#define W16096 "Both EODs are missing. Attempt to list index information."
#define E16097 "Both EODs are missing. Roll back operation is not permitted."
#define E16098 "Cannot roll back the cartridge: found unsupported index version."
#define E16099 "Use the latest version of LTFS software."
#define E16100 "Cannot recover the cartridge: found unsupported index version."
#define E16101 "Please use the latest version os LTFS software or --deep-recovery option."
#define E16102 "Cannot open key manager interface backend \'%s\'."
#define W16103 "Cannot unload key manager interface backend."
#define E16104 "Could not initialize the key manager interface plug-in. \'%s\' (%d)."
#define E16105 "Key manager interface backend option parsing failed."
#define E16106 "Tape backend option parsing failed."
#define E16107 "Unknown option '%s %s'."
#define I16108 "%s version %s."
#define E16109 "This operation is not allowed on this medium (%s)."
#define E16110 "The --salvage-rollback-points option was specified against a normal cartridge."
#define I16111 "The recovery process is skipped because of a locked cartridge (%d)."
#define W16112 "Cannot rename %s to %s (%d)."
#define W16113 "Cannot access to directory %s, disabled index capture mode (%d)."
#define I16114 "Index will be captured in %s."
#define I16115 "Index will not be captured."

// Help messages
#define I16400 "Usage: %s [options] filesys" \
  "filesys                           Device file for the tape drive" \
  "Available options are:" \
  "  -g, --generation=<generation>   Specify the generation to roll back" \
  "  -r, --rollback                  Roll back to the point specified by -g" \
  "  -n, --no-rollback               Do not roll back. Verify the point specified by -g (default)" \
  "  -f, --full-recovery             Recover extra data blocks into directory %s" \
  "  -l, --list-rollback-points      List rollback points" \
  "  -j, --erase-history             Erase history at rollback" \
  "  -k, --keep-history              Keep history at rollback (default)" \
  "  -q, --quiet                     Suppress informational messages" \
  "  -t, --trace                     Enable diagnostic output" \
  "  -h, --help                      This help" \
  "  -p, --advanced-help             Full help, including advanced options" \
  "  -i, --config=<file>             Use the specified configuration file (default: %s)" \
  "  -e, --backend=<name>            Override the default tape device backend" \
  "  -x, --fulltrace                 Enable full function call tracing (slow)" \
  "  -v, --traverse=<strategy>       Set traverse mode for listing roll back points. Strategy should be forward or backward. (default: backward)" \
  "  -z, --deep-recovery             Recover EOD missing cartridge." \
  "                                  Some blocks might be erased, but recover to final unmount point\n" \
  "                                  with an index version of at least "2.0.0" or earlier.\n" \
  "                                  (Must be used for a cartridge that cannot be recovered by a normal option.)" \
  "  -m, --full-index-info           Display full index information (Effective only for -l option)" \
  "      --kmi-backend=<name>        Override the default key manager interface backend" \
  "      --capture-index=<dir>       Capture indexes to the specified directory (-g is effective for this option)" \
  "      --syslogtrace               Enable diagnostic output to stderr and syslog" \
  "  -V, --version                   Version information" \
  "      --salvage-rollback-points   List the rollback points of the cartridge that has no EOD"
// "  -t, --time=<time>               Specify the time to roll back"
// "                                  Time value should be \"yyyy-mm-dd HH:MM:SS.nanosec\""
