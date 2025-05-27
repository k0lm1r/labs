cmake_minimum_required(VERSION 3.10.0)
project(lab LANGUAGES C)

set(CMAKE_C_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
endif()

add_executable(lab main.c stack.c fileCalculator.c functions.c workingWithStack.c)