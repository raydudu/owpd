cmake_minimum_required(VERSION 3.19)
project(shadebit LANGUAGES C)

add_executable(shacopr shacopr.c)
target_link_libraries(shacopr PRIVATE w1)

add_executable(shademo shademo.c)
target_link_libraries(shademo PRIVATE w1)

add_executable(sharov sharov.c)
target_link_libraries(sharov PRIVATE w1)

install(TARGETS sharov shademo shacopr)