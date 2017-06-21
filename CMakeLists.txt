cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES  escapeRoomWrapper.cpp EscapeRoom.h EscapeRoom.c EscapeRoomWrapper.h
        EscapeRoomWrapper-test.cpp
         Exceptions.h mtmtest.h)
add_executable(ex4_wet ${SOURCE_FILES})