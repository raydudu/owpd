cmake_minimum_required(VERSION 3.19)
project(swtloop LANGUAGES C)

add_executable(swtloop swtloop.c)
target_link_libraries(swtloop PRIVATE w1)

add_executable(swtoper swtoper.c)
target_link_libraries(swtoper PRIVATE w1)