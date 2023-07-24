cmake_minimum_required(VERSION 3.19)
project(temp LANGUAGES C)

if (W1_HW STREQUAL "DS87C550")
    add_executable(tempm tempm.c)
    target_link_libraries(tempm PRIVATE w1)

    install(TARGETS tempm)
endif ()

add_executable(temp temp.c)
target_link_libraries(temp PRIVATE w1)

add_executable(temp_DS18B20 temp_DS18B20.c)
target_link_libraries(temp_DS18B20 PRIVATE w1)

install(TARGETS temp temp_DS18B20)