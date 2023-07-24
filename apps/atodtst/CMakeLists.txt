cmake_minimum_required(VERSION 3.19)
project(atodtst LANGUAGES C)

add_executable(atodtst atodtst.c)
target_link_libraries(atodtst PRIVATE w1)

install(TARGETS atodtst)