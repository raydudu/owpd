cmake_minimum_required(VERSION 3.19)
project(counter LANGUAGES C)

add_executable(counter counter.c)
target_link_libraries(counter PRIVATE w1)

install(TARGETS counter)