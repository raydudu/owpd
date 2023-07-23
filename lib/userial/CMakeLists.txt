cmake_minimum_required(VERSION 3.19)
project(userial LANGUAGES C)

set(W1_HW "Linux" CACHE STRING "Hardware to use by ${PROJECT_NAME}")
set_property(CACHE W1_HW PROPERTY STRINGS
        "Linux" "Win32" "Mac" "DOS" "DS80C390" "DS80C400" "DS87C520" "DS87C550" "Palm" "PocketPC" "Win16")


set(HW_Linux link/Linux/linuxlnk.c)

set(HW_Win32 link/Win32/win32lnk.c)

set(HW_Mac link/Mac/maclnk.c)

set(HW_DOS link/DOS/udoslnk.c)

set(HW_DS80C390 link/DS80C390/ds390lnk.c)

set(HW_DS80C400 link/DS80C400/ds400lnk.c link/DS80C400/ser400.c link/DS80C400/ser400.h)
set(HW_DS80C400_INC link/DS80C400)

set(HW_DS87C520 link/DS87C520/ds520lnk.c)

set(HW_DS87C550 link/DS87C550/ds550lnk.c link/DS87C550/ser550.c link/DS87C550/ser550.h)
set(HW_DS87C550_INC link/DS87C550)

set(HW_Palm link/Palm/palmlnk.c)

set(HW_PocketPC link/PocketPC/WinCElnk.c link/PocketPC/WinCElnk.h)

set(HW_Win16 link/Win16/uwin16lk.c)

add_library(${PROJECT_NAME}
        shared/ds2480.h
        shared/ds2480ut.c
        shared/owllu.c
        shared/ownetu.c
        shared/owsesu.c
        shared/owtrnu.c
        ${HW_${W1_HW}})
target_include_directories(${PROJECT_NAME} PUBLIC shared ${HW_${W1_HW}_INC})
target_link_libraries(${PROJECT_NAME} PUBLIC w1common)