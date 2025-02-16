cmake_minimum_required(VERSION 3.27)

project(lab8)
add_library(functions_lib STATIC functions.c functions.h)
add_library(tasks_lib STATIC tasks.c tasks.h)
add_executable(lab main.c)
target_link_libraries(lab functions_lib tasks_lib)