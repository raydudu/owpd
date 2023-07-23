cmake_minimum_required(VERSION 3.19)
project(fish LANGUAGES C)

add_executable(fish fish.c)
target_link_libraries(fish PRIVATE w1)
