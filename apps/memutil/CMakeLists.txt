cmake_minimum_required(VERSION 3.19)
project(memutil LANGUAGES C)

add_executable(memutil memutil.c)
target_link_libraries(memutil PRIVATE w1)

install(TARGETS memutil)