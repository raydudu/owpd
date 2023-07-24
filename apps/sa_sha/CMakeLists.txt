cmake_minimum_required(VERSION 3.19)
project(sa_sha LANGUAGES C)

add_executable(sha_chck sha_chck.c)
target_link_libraries(sha_chck PRIVATE w1)

add_executable(sha_init sha_init.c)
target_link_libraries(sha_init PRIVATE w1)

install(TARGETS sha_init sha_chck)