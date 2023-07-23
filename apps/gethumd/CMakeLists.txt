cmake_minimum_required(VERSION 3.19)
project(gethumd LANGUAGES C)

add_executable(gethumd gethumd.c)
target_link_libraries(gethumd PRIVATE w1)
