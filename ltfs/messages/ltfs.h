#pragma once
/**
 * Message header definition for LTFS binary
 * range: 14000 - 14499
 */
#define I14000 "LTFS starting, %s version %s, log level %d."
#define E14001 "Cannot enable FUSE option %s (%d)."
#define E14002 "Cannot set up permissions (%d)."
#define E14003 "min_pool_size (%d) cannot be greater than max_pool_size (%d)."
#define E14004 "Cannot create work directory (%d)."
#define E14005 "Path '%s' exists, but is not a directory."
#define E14006 "Invalid umask '%s' (must be 3 octal digits, such as 022)."
#define E14007 "Invalid fmask '%s' (must be 3 octal digits, such as 022)."
#define E14008 "Invalid dmask '%s' (must be 3 octal digits, such as 022)."
#define E14009 "The backend '%s' does not have a default device. Specify one using the \"-o devname=\" option."
// #define E14010 "Cannot load I/O scheduler '%s'."
#define E14011 "Cannot allocate LTFS volume structure."
#define E14012 "Tape backend option parsing failed."
#define E14013 "Cannot mount the volume from %s."
// #define E14014 "Cannot duplicate index criteria."
#define W14015 "Volume does not allow index criteria override. Ignoring user-specified criteria."
#define E14016 "Cannot format data placement rules (%d)."
#define E14017 "Cannot parse data placement rules (%d)."
#define E14018 "Cannot get read-only status of the medium."
#define I14019 "Medium is write protected. Mounting read-only."
// #define E14020 "The data placement rules must be 255 characters or less."
// #define E14021 "The data placement rules contain invalid characters."
#define E14022 "Cannot flush file data to the medium. Data might be lost (%s)."
#define E14023 "Cannot set extended attribute: position option must be zero."
#define E14024 "Cannot get extended attribute: position option must be zero."
// #define D14025 "Cannot read directory: no file handle provided."
#define D14026 "Cannot read directory: no buffer space."
#define E14027 "Cannot read directory: convert to system locale failed (%s, %d)."
#define W14028 "Cannot initialize I/O scheduler. The scheduler is disabled. Performance might decrease and memory usage might increase."
#define I14029 "Ready to receive file system requests."
#define D14030 "FUSE fgetattr for '%s'."
#define D14031 "FUSE getattr for '%s'."
#define D14032 "FUSE open file '%s' (%s)."
#define D14033 "FUSE open directory '%s'."
#define D14034 "FUSE release directory '%s'."
#define D14035 "FUSE release file '%s'."
#define D14036 "FUSE fsync '%s'."
#define D14037 "FUSE flush '%s'."
#define D14038 "FUSE set times '%s'."
#define D14039 "FUSE chmod '%s'."
#define D14040 "FUSE create file '%s'."
#define D14041 "FUSE mkdir '%s'."
#define D14042 "FUSE truncate '%s' (length=%lld)."
#define D14043 "FUSE ftruncate '%s' (length=%lld)."
#define D14044 "FUSE unlink '%s'."
#define D14045 "FUSE rmdir '%s'."
#define D14046 "FUSE rename '%s' to '%s'."
#define D14047 "FUSE readdir '%s'."
#define D14048 "FUSE write '%s' (offset=%lld, count=%zu)."
#define D14049 "FUSE read '%s' (offset=%lld, count=%zu)."
#define D14050 "FUSE setxattr '%s' (name='%s', size=%zu)."
#define D14051 "FUSE getxattr '%s' (name='%s')."
#define D14052 "FUSE listxattr '%s'."
#define D14053 "FUSE removexattr '%s' (name='%s')."
#define E14054 "Failed to load tape drive plug-in (%d)."
#define E14055 "Failed to load I/O scheduler plug-in (%d)."
#define E14056 "No driver plug-in configured and no default found."
#define E14057 "Failed to load kmi plug-in (%d)."
#define I14058 "%s version %s."
// #define E14059 "No changer plug-in configured and no default found."
#define E14060 "Failed to convert the sync time (%s)."
#define E14061 "Unknown type of sync (%s)."
#define I14062 "Sync time is 0. Set sync type \"none\"."
#define I14063 "Sync type is \"%s\", Sync time is %ld sec."
#define I14064 "Sync type is \"%s\"."
#define E14065 "Unexpected sync type (%d)."
#define E14066 "Sync time should be a positive value."
#define E14067 "Failed to convert the sync time because it is too big or too small (%s)."
#define E14068 "Specified sync time is too big or too small (%ld)."
// #define E14069 "Failed to load changer plug-in (%d)."
// #define E14070 "The backend '%s' does not have a default device. Specify one using the \"-o changer_devname=\" option."
#define I14071 "Medium has no space to write data. Mounting as read-only."
#define I14072 "Rollback mount is specified. Mounting as read-only at generation %d."
#define I14073 "Index partition has no space to write index. Mounting as read-only."
#define I14074 "Data partition has no space to write index. Mounting as read-only."
#define E14075 "Cannot set up tape drive."
#define I14076 "Attempting to mount the cartridge without EOD existence check."
#define I14077 "The cartridge will be mounted as read-only."
#define I14078 "Medium is Read-Only in this device."
#define E14079 "Invalid uid '%s' (must be a positive integer or valid user name)."
#define E14080 "Invalid gid '%s' (must be a positive integer or valid group name)."
// #define E14081 "Failed to create a dentry cache view for cartridge \"%s\"."
// #define E14082 "Failed to enable dentry cache for cartridge \"%s\"."
// #define E14083 "Failed to remove existing dentry cache for cartridge \"%s\" (%d)."
// #define E14084 "Failed to load the dentry cache module (%d)."
// #define E14085 "Could not initialize the dentry cache manager (%d)."
// #define E14086 "Could not configure the dentry cache manager (%d)."
// #define E14087 "Failed to unload the dentry cache module (%d)."
// #define E14088 "Failed to destroy the dentry cache manager (%d)."
#define E14089 "Could not initialize the kmi plug-in."
#define E14090 "KMI backend option parsing failed."
#define E14091 "Invalid generation for rollback mount is specified. %s."
#define I14092 "Symbolic link type is (%s)."
#define E14093 "Unknown type of symbolic link (%s)."
#define E14094 "Cannot get mount point (%d)."
#define I14095 "Set the tape device write-anywhere mode to avoid cartridge ejection."
// #define W14100 "The device name specified with '-o devname' is ignored in library mode."
// #define W14101 "The eject option is not available in library mode."
// #define E14102 "Time-based sync is not available in library mode."
// #define E14103 "Cannot specify both a single drive name and a changer device name."
#define I14104 "Launched by \"%s\"."
#define I14105 "%s."
#define I14106 "GCC version is %s."
// #define W14107 "d->dentry_proxy is NULL unexpectedly: %s."
// #define E14108 "The single drive feature is not supported in this binary."
#define E14109 "Minimum pool size must be a positive number."
#define E14110 "Maximum pool size must be a positive number."
#define I14111 "Initial setup completed successfully."
#define I14112 "Invoke 'mount' command to check the result of final setup."
#define I14113 "Specified mount point is listed if succeeded."
#define E14114 "Cannot initialize the open file table."
#define E14115 "Invalid scsi_append_only_mode option: %s."
#define E14116 "This medium is not supported (%d)."
#define I14117 "Metadata only rollback mount is specified. Mounting as meta read-only from %s."
#define E14118 "Unexpected option is specified for read only mount (%d)."
#define I14119 "Rollback mount from index file is specified. Mounting as read-only from %s."
#define W14120 "Cannot access to directory %s, disabled index capture mode (%d)."
#define I14121 "Index will be captured at %s at update"
#define I14122 "Index will not be captured."
#define W14123 "The main function of FUSE returned error (%d)."

// // 14150 - 14199 are reserved for LE+

// Help message
#define I14400 \
  "usage: %s mountpoint [options]" \
  "LTFS options:" \
  "    -o devname=<dev>          Tape device (default: %s)" \
  "    -o devname=<dev>          Tape device" \
  "    -o work_directory=<dir>   LTFS work directory (default: %s)" \
  "    -o trace                  Enable diagnostic output (same as verbose=3)" \
  "    -a                        Advanced help, including standard FUSE options" \
  "    -V, --version             Output version information and exit" \
  "    -h, --help                Display this help and exit" \
  "FUSE options:" \
  "    -o umask=M                Set file permissions (octal)" \
  "    -o uid=N                  Set file owner" \
  "    -o gid=N                  Set file group" \
  "    -o config_file=<file>     Configuration file (default: %s)" \
  "    -o atime                  Update index if only access times have changed" \
  "    -o tape_backend=<name>    tape backend to use (default: %s)" \
  "    -o iosched_backend=<name> I/O scheduler implementation to use (default: %s, use \"none\" to disable)" \
  "    -o umask=<mode>           Override default permission mask (3 octal digits, default: 000)" \
  "    -o fmask=<mode>           Override file permission mask (3 octal digits, default: 000)" \
  "    -o dmask=<mode>           Override directory permission mask (3 octal digits, default: 000)" \
  "    -o min_pool_size=<num>    Minimum write cache pool size. Cache objects are 1 MB each (default: %d)" \
  "    -o max_pool_size=<num>    Maximum write cache pool size. Cache objects are 1 MB each (default: %d)" \
  "    -o rules=<rules>          Rules for choosing files to write to the index partition.\n" \
  "                              The syntax of the rule argument is:\n" \
  "                              size=1M\n" \
  "                              size=1M/name=pattern\n" \
  "                              size=1M/name=pattern1:pattern2:pattern3\n" \
  "                              A file is written to the index partition if it is no larger\n" \
  "                              than the given size AND matches at least one of the name\n" \
  "                              patterns (if specified). The size argument accepts K, M, and G\n" \
  "                              suffixes. Name patterns might contain the special characters\n" \
  "                              '?' (match any single character) and '*' (match zero or more\n" \
  "                              characters)" \
  "    -o quiet                  Disable informational messages (same as verbose=1)" \
  "    -o fulltrace              Enable full call tracing (same as verbose=4)" \
  "    -o eject                  Eject the cartridge after unmount" \
  "    -o sync_type=<type>       Specify sync type (default: time@5)\n" \
  "                              <type> should be specified as follows:\n" \
  "                              time@min:  LTFS attempts to write an index each 'min' minutes.\n" \
  "                                         min should be a decimal number from 1 to %ld\n" \
  "                                         It is equivalent to \"-o sync_type=unmount\" when 0 is specified\n" \
  "                                         (default: min=5)\n" \
  "                              close:     LTFS attempts to write an index when a file is closed\n" \
  "                              unmount:   LTFS attempts to write an index when the medium is unmounted" \
  "    -o device_list            Show available tape devices" \
  "    -o rollback_mount=<gen|index_file>  Attempt to mount on previous index generation on tape or specified index file (read-only mount)" \
  "    -o noeject                Do not eject the cartridge after unmount (default)" \
  "    -o noatime                Do not update index if only access times have changed (default)" \
  "    -o verbose=<num>          Override output verbosity directly (default: %d)" \
  "    -o force_mount_no_eod     Skip EOD existence check when mounting (read-only mount)\n"\
  "                              Only use for a CM corrupted medium" \
  "    -o release_device         Clear device reservation (should be specified with -o devname" \
  "    -o kmi_backend=<name>     Key manager interface implementation to use (default: %s, use \"none\" to disable)" \
  "    -o capture_index=<dir>    Capture index to the specified directory by dir when index is updated" \
  "    -o symlink_type=<type>    Specify symbolic link type (default: posix)\n" \
  "                              <type> should be specified with one of the following values:\n" \
  "                              posix:  LTFS behavior is same as standard symbolic link\n" \
  "                              live:   LTFS replaces mount point path by current mount point" \
  "    -o scsi_append_only_mode=<on|off>  Set the tape device append-only mode (default=on)" \
  "    -o syslogtrace            Enable diagnostic output to stderr and syslog(same as verbose=303)"
