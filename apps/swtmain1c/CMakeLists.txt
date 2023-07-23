cmake_minimum_required(VERSION 3.19)
project(swtmain1c LANGUAGES C)

add_executable(swtmain1c swtmain1c.c)
target_link_libraries(swtmain1c PRIVATE w1)
