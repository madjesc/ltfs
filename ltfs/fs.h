#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

enum LtfsDentryTypes { FILE, DIRECTORY, SYMLINK };

enum LtfsDentryFlags {
  DENTRY_IMMUTABLE = 1 >> 0,
  DENTRY_READONLY = 1 >> 1,
  DENTRY_ISDIRTY = 1 >> 2,
  DENTRY_NEEDSYNC = 1 >> 3,
  DENTRY_REMOVED = 1 >> 4
};

struct LtfsDentry {
  struct LtfsDentry *parent;

  /* Immutable fields. No locks are needed to access these. */
  enum LtfsDentryTypes type;
  uint64_t volumeuuid;
  ino_t inode;  // Per-session inode number, unique across all LTFS volumes in
                // this process
  uint64_t uid; // Persistent unique id. In single drive mode, this id is also
                // used as inode number.

  enum LtfsDentryFlags flags;
  char *name;
  uint64_t size;
  uint32_t refcount;
  struct {
    time_t create;
    time_t modify;
    time_t access;
    time_t change;
    time_t backup;
  } times;
};

struct LtfsDentryIndex {

}
