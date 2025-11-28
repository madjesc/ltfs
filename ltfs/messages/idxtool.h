#pragma once
/**
 * Message header definition for LTFSIDX binary
 * range: 19500 - 19989
 */
#define I19500 "Starting ltfsindextool, %s version %s, log level %d."
#define E19501 "Cannot allocate LTFS volume structure."
#define I19502 "%s."
#define I19503 "GCC version is %s."
#define I19504 "Capture all indexes from both partitions."
#define I19505 "Capture all indexes from (%u, %llu)."
#define D19506 "Opening the device."
#define D19507 "Device opened."
#define E19508 "Cannot open backend \'%s\'."
#define E19509 "Cannot open key manager interface backend \'%s\'."
#define E19510 "Cannot open device \'%s\' (%d)."
#define E19511 "Could not initialize the key manager interface plug-in. \'%s\' (%d)."
#define E19512 "Key manager interface backend option parsing failed."
#define E19513 "Tape backend option parsing failed."
#define E19514 "Unknown option '%s %s'."
#define E19515 "Cannot set up tape device."
#define E19516 "Cannot allocate the read buffer."
#define E19517 "Cannot seek to the start position (%u, %llu, %d)."
#define E19518 "Cannot get the current position (%d)."
#define E19519 "Cannot read a block (%u, %llu, %ld)."
#define D19520 "Closing the device."
#define W19521 "Cannot unload backend."
#define D19522 "Device closed."
#define I19523 "Failed to capture index (%d)."
#define I19524 "Captured indexes successfully."
#define D19525 "Validating command line options."
#define E19526 "File name to check or device name to capture must be specified."
#define D19527 "Command line options are valid."
#define W19528 "Cannot unload key manager interface backend."
#define I19529 "Reading an index from (%u, %llu)."
#define I19530 "Block in (%u, %llu) does not look an index, seek to next position (%d)."
#define E19531 "Cannot seek to the next position (%u, %llu, %d)."
#define E19532 "Cannot allocate the file name."
#define E19533 "Cannot open the file %s (%d)."
#define I19534 "Reached to EOD (%u, %llu)."
#define I19535 "Reached to EOD but cannot get the position (%d)."
#define E19536 "Cannot write a block (%ld, %d)."
#define I19537 "Detected the end of the index (%u, %llu)."
#define E19538 "Detected the EOD in the middle of index (%u, %llu)."
#define I19539 "Wrote an index, length is %llu."
#define E19540 "Partition number must be 0 or 1."
#define E19541 "Operation mode is wrong."
#define I19542 "Launched by \"%s\"."
#define I19543 "Checking the index file \"%s\"."
#define I19544 "Checked the index successfully."
#define E19545 "Failed to check the index (%d)."
#define I19546 "%s version %s."
#define I19547 "Creating an index file: %s"
#define E19548 "Start position shall be 5 or larger (%llu)."

// Help messages
#define I19900 "Usage: %s [options] [filename]" \
  "Available options are:" \
  "  -d, --device=<name>        Tape device (Capture index to specified file when this option is specified. Otherwise run check process with specified file)" \
  "  -p, --partition=<part_num> Partition number 0 or 1, capture both partitions if not specified" \
  "  -s, --start-pos=<block>    Block number to start capturing (default: %d)" \
  "      --output-dir=<dir>     Directory to store captured indexes (default: \'%s\')" \
  "  -b, --blocksize=<num>      Specify the LTFS record size (default: %d)" \
  "  -i, --config=<file>        Use the specified configuration file (default: %s)" \
  "  -e, --backend=<name>       Use the specified tape device backend (default: %s)" \
  "      --kmi-backend=<name>   Use the specified key manager interface backend (default: %s)" \
  "  -q, --quiet                Suppress progress information and general messages" \
  "  -t, --trace                Enable function call tracing" \
  "  -V, --version             Version information" \
  "  -h, --help                 This help" \
  "Usage example:" \
  "  %s --device=%s -p=%d"
