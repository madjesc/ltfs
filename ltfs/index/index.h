#pragma once
#include <asm-generic/int-ll64.h>
#include <cstdint>
#include <linux/types.h>
#include <stdint.h>
#include <time.h>

enum LtfsIndexItemType {
  ITEM_INODE,
  ITEM_DENTRY,
  ITEM_XATTR,
};

struct LtfsIndexHeader {
  uint64_t volumeuuid[2];
  uint32_t generation;
  time_t updated;
  uint64_t count;
  struct {
    uint8_t partition;
    uint64_t startblock;
  } self, prev;
};

struct LtfsIndexKey {
  uint64_t uid;
  enum LtfsIndexItemType type;
  uint64_t order;
};

struct LtfsIndexItem {
  struct LtfsIndexKey ikey;
  uint64_t offset;
};
