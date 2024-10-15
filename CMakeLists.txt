cmake_minimum_required(VERSION 3.29)
project(lab5 C)

set(CMAKE_C_STANDARD 23)
add_library(library STATIC library.h library.c)

add_executable(lab5 main.c)
target_link_libraries(lab5 library)
add_executable(temp temp.c)
target_link_libraries(temp library)