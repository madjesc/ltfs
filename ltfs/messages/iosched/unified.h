#pragma once
/**
 * Message header definition for IOSCHED UNIFIED module
 * range: 13005 - 13499
 */

#define E13005 "Cannot initialize scheduler: failed to initialize cache manager."
#define E13006 "Cannot initialize scheduler: failed to initialize mutex %s (%d)."
#define E13007 "Cannot initialize scheduler: failed to initialize condition variable %s (%d)."
#define E13008 "Cannot initialize scheduler: failed to create thread %s (%d)."
#define E13009 "Failed to initialize mutex in scheduler private data (%d)."
#define E13010 "Cannot write: failed to allocate scheduler private data (%d)."
#define E13011 "Invalid back pointer to the dentry in the dentry_priv structure."
#define E13012 "Invalid request_state received when updating the queue membership (%d)."
#define W13013 "Index partition writer: failed to write data to the tape (%d)."
#define W13014 "Data partition writer: failed to write data to the tape (%d)."
#define D13015 "Unified I/O scheduler initialized."
#define D13016 "Unified I/O scheduler uninitialized."
#define E13017 "Cannot write: failed to allocate a cache block (%d)."
#define E13018 "Cannot write: failed to allocate a write request."
#define E13019 "Cannot flush: failed to write to data partition (%d)."
#define E13020 "Aborting full flush: flushing dentry '%s' failed (%d)."
#define W13021 "Failed to save index partition extents for a dentry (%d)."
#define W13022 "Freeing a dentry priv with outstanding write requests. This is a bug."
//unused #define W13023 "Failed to copy a request: will stop writing file to the index partition."
#define I13024 "Clean up extents and append index at index partition (%d)."
#define I13025 "Truncate extents larger than position (%d, %lld), block size = %ld."
#define E13026 "Write perm handling error : %s (%d)."
#define I13027 "Error position is larger than last index position: (%d, %lld), last index = %lld."
