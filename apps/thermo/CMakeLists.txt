cmake_minimum_required(VERSION 3.19)
project(thermo LANGUAGES C)

add_executable(thermodl thermodl.c)
target_link_libraries(thermodl PRIVATE w1)

add_executable(thermoms thermoms.c)
target_link_libraries(thermoms PRIVATE w1)

install(TARGETS thermoms thermodl)