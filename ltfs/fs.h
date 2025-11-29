#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

enum LtfsINodeType { FILE, DIRECTORY, SYMLINK };

struct LtfsINode {
  enum LtfsINodeType type;
  bool immutable;
  uint64_t volumeuuid;
  uint64_t size;
  uint64_t block;
  // Per-session inode number, unique across all LTFS volumes in
  // this process
  uint32_t refcount;
  struct {
    time_t create;
    time_t modify;
    time_t access;
    time_t change;
    time_t backup;
  } times;

  // TODO: Add permission and ownership fields
};

struct LtfsDentry {
  ino_t inode;
  char *name;
  // TODO: Add extended attributes to the dentry
};
