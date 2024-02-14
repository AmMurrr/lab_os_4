cmake_minimum_required (VERSION 3.10)
project(lab_os_4)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(imp1 SHARED implic_1.c)
target_link_libraries(imp1 m)
add_library(imp2 SHARED implic_2.c)
target_link_libraries(imp2 m)

add_executable(comp main_com.c)
target_link_libraries(comp imp1)

add_executable(run main_run.c)

