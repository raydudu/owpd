cmake_minimum_required(VERSION 3.19)
project(tstfind LANGUAGES C)

if (W1_HW STREQUAL "DS87C550")
    add_executable(tstfindm tstfindm.c)
    target_link_libraries(tstfindm PRIVATE w1)
endif ()

add_executable(tstfind tstfind.c)
target_link_libraries(tstfind PRIVATE w1)
