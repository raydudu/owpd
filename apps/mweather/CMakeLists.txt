cmake_minimum_required(VERSION 3.19)
project(mweather LANGUAGES C)

add_executable(mweather mweather.c)
target_link_libraries(mweather PRIVATE w1)

install(TARGETS mweather)