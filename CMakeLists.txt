cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "g++ -std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES  list.h list_example.cpp mtmtest.h Exceptions.h )
add_executable(ex4_wet ${SOURCE_FILES})