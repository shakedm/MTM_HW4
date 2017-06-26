cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES  ScaryRoomTest.cpp ScaryRoom.cpp ScaryRoom.h Enigma.h Enigma.cpp
         EscapeRoomWrapper.h escapeRoomWrapper.cpp EscapeRoom.h EscapeRoom.c mtmtest.h Exceptions.h )
add_executable(ex4_wet ${SOURCE_FILES})