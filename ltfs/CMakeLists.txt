add_library(libltfs SHARED
  logger.c
)
set_target_properties(libltfs PROPERTIES PREFIX "")

add_executable(ltfs
  ltfs.c
)
target_link_libraries(ltfs libltfs)
