cmake_minimum_required(VERSION 3.19)
project(sa_ps LANGUAGES C)

add_executable(ps_check ps_check.c)
target_link_libraries(ps_check PRIVATE w1)

add_executable(ps_init ps_init.c)
target_link_libraries(ps_init PRIVATE w1)