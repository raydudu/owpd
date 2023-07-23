cmake_minimum_required(VERSION 3.19)
project(usbds2490 LANGUAGES C)

find_package(PkgConfig)

pkg_check_modules(LIBUSB REQUIRED libusb)
#TODO for windows use built-in library if not found?

add_library(${PROJECT_NAME} STATIC
        libusbds2490.c
        libusbds2490.h
        libusblnk.c
        libusbnet.c
        libusbses.c
        libusbtran.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBUSB_INCLUDEDIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBUSB_LIBRARIES} w1common)
target_link_directories(${PROJECT_NAME} PUBLIC ${LIBUSB_LIBDIR})