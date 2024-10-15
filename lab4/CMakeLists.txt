cmake_minimum_required(VERSION 3.29)
project(lab4 C)

set(CMAKE_C_STANDARD 23)

include_directories(include)
add_library(library STATIC library.h library.c)
add_executable(lab4 main.c)
target_link_libraries(lab4 library)
add_executable(temp temp.c)
