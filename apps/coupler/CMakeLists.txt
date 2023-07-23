cmake_minimum_required(VERSION 3.19)
project(coupler LANGUAGES C)

add_executable(coupler coupler.c)
target_link_libraries(coupler PRIVATE w1)
