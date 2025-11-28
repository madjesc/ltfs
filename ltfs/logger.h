#pragma once
#include <stdbool.h>

enum LtfsLogLevel {
  NONE,
  ERROR,
  INFO,
  WARNING,
  DEBUG,
};
void LoggerShowThread(void);
void LoggerShowTime(void);

#define ltfsmsg(msg, ...)                                                      \
  {                                                                            \
    enum LtfsLogLevel level = NONE;                                            \
    switch (msg[0]) {                                                          \
    case 'E':                                                                  \
      level = ERROR;                                                           \
      break;                                                                   \
    case 'I':                                                                  \
      level = INFO;                                                            \
      break;                                                                   \
    case 'W':                                                                  \
      level = WARNING;                                                         \
      break;                                                                   \
    case 'D':                                                                  \
      break;                                                                   \
    default:                                                                   \
      level = NONE;                                                            \
      break;                                                                   \
    };                                                                         \
    ltfslog(level, #msg" "msg, ##__VA_ARGS__);                                       \
  }
void ltfslog(enum LtfsLogLevel level, const char *restrict message, ...);
