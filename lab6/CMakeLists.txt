cmake_minimum_required(VERSION 3.29)
project(lab6 C)

set(CMAKE_C_STANDARD 23)

add_library(library STATIC library.c library.h)
add_executable(lab6 main.c)
target_link_libraries(lab6 library)
add_executable(temp temp.c)
