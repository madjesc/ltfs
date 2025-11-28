#include <stdio.h>
#include <stdlib.h>
#include <sys/syslog.h>
#include "logger.h"

int main(int argc, char *argv[]) {
  openlog(NULL, LOG_PID, 0);
  LoggerShowThread();
  closelog();
  return 0;
}
