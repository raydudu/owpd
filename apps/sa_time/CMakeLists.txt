cmake_minimum_required(VERSION 3.19)
project(sa_time LANGUAGES C)

add_executable(tm_check tm_check.c)
target_link_libraries(tm_check PRIVATE w1)

add_executable(tm_init tm_init.c)
target_link_libraries(tm_init PRIVATE w1)

install(TARGETS tm_init tm_check)