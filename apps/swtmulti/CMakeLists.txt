cmake_minimum_required(VERSION 3.19)
project(swtmulti LANGUAGES C)

add_executable(swtmulti swtmulti.c)
target_link_libraries(swtmulti PRIVATE w1)
