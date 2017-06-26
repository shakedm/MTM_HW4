cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES  Enigma.h EscapeRoom.c escapeRoomWrapper.cpp Enigma.cpp
        EscapeRoomWrapper.h EscapeRoomWrapper-test.cpp mtmtest.h Exceptions.h
        EscapeRoom.h KidsRoom.cpp KidsRoom.h)
add_executable(ex4_wet ${SOURCE_FILES})