cmake_minimum_required(VERSION 3.10)

project(ltfs
  VERSION 2.4.8.1
  LANGUAGES C
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(Threads REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libxml2)
include_directories(uthash/include)

add_subdirectory(man)
add_subdirectory(src)
