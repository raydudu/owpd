cmake_minimum_required(VERSION 3.19)
project(shaapp LANGUAGES C)

add_executable(shaapp shaapp.c)
target_link_libraries(shaapp PRIVATE w1)

install(TARGETS shaapp)