#include "EscapeRoomWrapper.h"
#include "mtmtest.h"
#include <functional>
#include <string>
#include <iostream>

using namespace mtm::escaperoom;

void equal(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room21((char *)"room21", 1);

    EscapeRoomWrapper room11_copy(room11);
    EscapeRoomWrapper room21_copy(room21);

    EscapeRoomWrapper assigned_room = room14;

    ASSERT_EQUALS(room11 , room11_copy); //checks both copy_constructor & == operator
    ASSERT_EQUALS(room21 , room21_copy); //checks both copy_constructor & == operator
    ASSERT_EQUALS(room14 , assigned_room); //checks assignment & operator
    ASSERT_EQUALS(room13, room13);
}

void not_equal() {
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2); // max escape time
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2); // min escape time
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2); // max level
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2); // min level
    EscapeRoomWrapper room21((char *)"room21", 1); // accept min level
    EscapeRoomWrapper room22((char *)"room22", 10); // accept max level
    EscapeRoomWrapper room23((char *)"room23", 5); // accept mid level

    EscapeRoomWrapper room11_copy(room11);

    EscapeRoomWrapper assigned_room = room14;

    ASSERT_NOT_EQUAL(room11 , room13);
    ASSERT_NOT_EQUAL(room22 , room23);
    ASSERT_NOT_EQUAL(assigned_room, room11_copy);
    ASSERT_NOT_EQUAL(room12, room21);
}

void less_than(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);

    ASSERT_TRUE(room11 < room13);
    ASSERT_FALSE(room11 < room15);
    ASSERT_FALSE(room22 < room21);
}

void greater_than(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);

    EscapeRoomWrapper room11_copy(room11);

    ASSERT_FALSE(room11 > room11_copy);
    ASSERT_TRUE(room11 > room15);
    ASSERT_TRUE(room22 > room21);
}

void print(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room21((char *)"room21", 1);

    EscapeRoomWrapper room21_copy(room21);
    EscapeRoomWrapper assigned_room = room14;

    ASSERT_PRINT("room11 (90/5/2)", room11);
    ASSERT_PRINT("room21 (60/1/6)", room21_copy);
    ASSERT_PRINT("room14 (70/1/2)", assigned_room);
}

void check_level(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);
    EscapeRoomWrapper room23((char *)"room23", 5);

    EscapeRoomWrapper room21_copy(room21);

    ASSERT_EQUALS(5, room11.level());
    ASSERT_EQUALS(10, room13.level());
    ASSERT_EQUALS(1, room14.level());
    ASSERT_EQUALS(1, room21_copy.level());
    ASSERT_NOT_EQUAL(7, room12.level());
    ASSERT_NOT_EQUAL(7, room15.level());
    ASSERT_NOT_EQUAL(7, room22.level());
    ASSERT_NOT_EQUAL(7, room23.level());
}

void check_getName(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);
    EscapeRoomWrapper room23((char *)"room23", 5);

    EscapeRoomWrapper assigned_room = room14;
    EscapeRoomWrapper room21_copy(room21);

    ASSERT_EQUALS("room11", room11.getName());
    ASSERT_EQUALS("room13", room13.getName());
    ASSERT_EQUALS("room14", assigned_room.getName());
    ASSERT_EQUALS("room21", room21_copy.getName());
    ASSERT_NOT_EQUAL("bla", room12.getName());
    ASSERT_NOT_EQUAL("room52", room15.getName());
    ASSERT_NOT_EQUAL("room2", room22.getName());
    ASSERT_NOT_EQUAL("room32", room23.getName());
}

void check_getMaxTime(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);
    EscapeRoomWrapper room23((char *)"room23", 5);

    EscapeRoomWrapper room21_copy(room21);

    ASSERT_EQUALS(90, room11.getMaxTime());
    ASSERT_EQUALS(70, room13.getMaxTime());
    ASSERT_EQUALS(70, room14.getMaxTime());
    ASSERT_EQUALS(60, room21_copy.getMaxTime());
    ASSERT_NOT_EQUAL(40, room12.getMaxTime());
    ASSERT_NOT_EQUAL(7, room15.getMaxTime());
    ASSERT_NOT_EQUAL(7, room22.getMaxTime());
    ASSERT_NOT_EQUAL(7, room23.getMaxTime());
}

void check_getMaxParticipants(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room22((char *)"room22", 10);
    EscapeRoomWrapper room23((char *)"room23", 5);

    EscapeRoomWrapper assigned_room = room14;
    EscapeRoomWrapper room21_copy(room21);

    ASSERT_EQUALS(2, room11.getMaxParticipants());
    ASSERT_EQUALS(2, room13.getMaxParticipants());
    ASSERT_EQUALS(1000000, assigned_room.getMaxParticipants());
    ASSERT_EQUALS(6, room21_copy.getMaxParticipants());
    ASSERT_NOT_EQUAL(7, room12.getMaxParticipants());
    ASSERT_NOT_EQUAL(7, room15.getMaxParticipants());
    ASSERT_NOT_EQUAL(7, room22.getMaxParticipants());
    ASSERT_NOT_EQUAL(7, room23.getMaxParticipants());
}

void check_rate(){
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2);
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2);
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2);
    EscapeRoomWrapper room21((char *)"room21", 1);
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2);

    EscapeRoomWrapper room21_copy(room21);
    EscapeRoomWrapper room11_copy(room11);

    EscapeRoomWrapper assigned_room = room14;

    //rate:
    room11.rate(11);
    room21_copy.rate(21);
    assigned_room.rate(14);

    //getRate:
    ASSERT_EQUALS(11, room11.getRate());
    ASSERT_EQUALS(0, room13.getRate());
    ASSERT_EQUALS(14, assigned_room.getRate());
    ASSERT_EQUALS(21, room21_copy.getRate());
    ASSERT_EQUALS(0, room12.getRate());
    ASSERT_NOT_EQUAL(11, room11_copy.getRate());
    ASSERT_NOT_EQUAL(21, room21.getRate());
    ASSERT_NOT_EQUAL(14, room14.getRate());
}

void ERWTestsBasic(){
    //create various rooms in good strat values range (checking both builders):
    EscapeRoomWrapper room11((char *)"room11", 90, 5, 2); // max escape time
    EscapeRoomWrapper room12((char *)"room12", 30, 5, 2); // min escape time
    EscapeRoomWrapper room13((char *)"room13", 70, 10, 2); // max level
    EscapeRoomWrapper room14((char *)"room14", 70, 1, 2); // min level
    EscapeRoomWrapper room15((char *)"room15", 70, 5, 1000000); // large partic.
    EscapeRoomWrapper room21((char *)"room21", 1); // accept min level
    EscapeRoomWrapper room22((char *)"room22", 10); // accept max level
    EscapeRoomWrapper room23((char *)"room23", 5); // accept mid level

    //check copy builder:
    EscapeRoomWrapper room11_copy(room11);
    EscapeRoomWrapper room21_copy(room21);

    //check assignment:
    EscapeRoomWrapper assigned_room = room14;
}



int main() {
    RUN_TEST(ERWTestsBasic);
    RUN_TEST(equal);
    RUN_TEST(not_equal);
    RUN_TEST(less_than);
    RUN_TEST(greater_than);
    RUN_TEST(print);
    RUN_TEST(check_level);
    RUN_TEST(check_getName);
    RUN_TEST(check_getMaxTime);
    RUN_TEST(check_getMaxParticipants);
    RUN_TEST(check_rate);
    std::cout << "All Done!" << std::endl;
}

