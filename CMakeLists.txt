cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES Company.h Enigma.h EscapeRoomWrapper.h EscapeRoom.h
        EscapeRoom.c Exceptions.h list_example.cpp mtmtest.h test1.cpp
        Enigma.cpp escapeRoomWrapper.cpp EscapeRoomWrapper-test.cpp)
add_executable(ex4_wet ${SOURCE_FILES})