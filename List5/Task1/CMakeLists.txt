cmake_minimum_required(VERSION 3.7.2)
project(Task1)
#file(GLOB SOURCES "/usr/xenomai/include/alchemy/*.*")
include_directories(/usr/include/xenomai/include/alchemy/)
#include_directories(/usr/include/xenomai/include/)
include_directories(/usr/include/xenomai/cobalt/)
include_directories(/usr/include/xenomai/)

execute_process(COMMAND xeno-config --skin=alchemy --cflags OUTPUT_VARIABLE XENO_NATIVE_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND xeno-config --skin=alchemy --ldflags OUTPUT_VARIABLE XENO_ALCHEMY_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)


SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -Wall -O3 ${XENO_NATIVE_CFLAGS} -DHAVE_SOCKLEN_T")
SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed ${XENO_ALCHEMY_LDFLAGS}")


add_executable(task1 task1.c)

SET_TARGET_PROPERTIES(task1 PROPERTIES LINK_FLAGS ${CMAKE_SHARED_LINKER_FLAGS})
