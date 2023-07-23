cmake_minimum_required(VERSION 3.19)
project(swtduo LANGUAGES C)

add_executable(swtduo swtduo.c)
target_link_libraries(swtduo PRIVATE w1)
