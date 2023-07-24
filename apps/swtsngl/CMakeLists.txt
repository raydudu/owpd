cmake_minimum_required(VERSION 3.19)
project(swtsngl LANGUAGES C)

add_executable(swtsngl swtsngl.c)
target_link_libraries(swtsngl PRIVATE w1)

install(TARGETS swtsngl)