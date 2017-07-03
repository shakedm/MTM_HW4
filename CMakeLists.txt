cmake_minimum_required(VERSION 3.7)
project(ex4_wet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -pedantic-errors -DNDEBUG")


set(SOURCE_FILES  Company.cpp Company.h Enigma.cpp Enigma.h EscapeRoom.h EscapeRoom.c
        EscapeRoomWrapper.h escapeRoomWrapper.cpp KidsRoom.h KidsRoom.cpp
        ScaryRoom.h ScaryRoom.cpp Exceptions.h mtmtest.h ./tests/CompanyTest.cpp)
add_executable(ex4_wet ${SOURCE_FILES})