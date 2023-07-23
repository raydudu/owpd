cmake_minimum_required(VERSION 3.19)
project(humalog LANGUAGES C)

add_executable(humalog humalog.c)
target_link_libraries(humalog PRIVATE w1)
