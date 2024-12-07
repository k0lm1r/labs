cmake_minimum_required(VERSION 3.29)
project(lab7 C)

set(CMAKE_C_STANDARD 23)
add_library(library STATIC library.c library.h)

add_executable(lab7 main.c)
target_link_libraries(lab7 library)