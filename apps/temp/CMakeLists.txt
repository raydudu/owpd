cmake_minimum_required(VERSION 3.19)
project(temp LANGUAGES C)

if (W1_HW STREQUAL "DS87C550")
    add_executable(tempm tempm.c)
    target_link_libraries(tempm PRIVATE w1)
endif ()

add_executable(temp temp.c)
target_link_libraries(temp PRIVATE w1)
