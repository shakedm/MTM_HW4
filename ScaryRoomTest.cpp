#include "ScaryRoom.h"
#include "mtmtest.h"
#include "Exceptions.h"

using mtm::escaperoom::ScaryRoom
using mtm::escaperoom::ScaryRoomIllegalAgeLimit
void SCRbasic(){
    ScaryRoom room1((char*)"room1",30,1,2,18,4);
    ScaryRoom room2((char*)"room2",90,10,20,20,20);
    ScaryRoom room3((char*)"room3",89,9,10000,100,2000);
    ScaryRoom room4((char*)"room4",50,8,1,1,1);
    ScaryRoom room5((char*)"room5",31,6,6,6,6);
    ScaryRoom room6((char*)"illegal",30,1,2,-1,2);

    ASSERT_EQUALS(room3.getAgeLimit(),18);
    room5=room4;
    room3=room4;
    ASSERT_EQUALS(room3.getAgeLimit(),1);
    ASSERT_EQUALS(room4.getAgeLimit(),1);
    ASSERT_EQUALS(room5.getAgeLimit(),1);
    ASSERT_EQUALS(room3.level(),8);
    ASSERT_EQUALS(room4.level(),8);
    ASSERT_NOT_EQUAL(room5.getMaxTime(),31);
    ASSERT_EQUALS(room5.getMaxTime(),50);
    ASSERT_EQUALS(room1.level(),1);
    ASSERT_EQUALS(room1.getMaxTime(),30);
    ASSERT_NOT_EQUAL(room6.getAgeLimit(),-1);//could be a problem
}
void SCRageLimit(){
    ScaryRoom room1((char*)"room1",30,1,2,18,4);
    ScaryRoom room2((char*)"room2",90,10,20,20,20);
    ScaryRoom room3((char*)"room3",89,9,10000,100,2000);

    ASSERT_EQUALS(room1.getAgeLimit(),18);
    ASSERT_EQUALS(room2.getAgeLimit(),20);
    ASSERT_EQUALS(room3.getAgeLimit(),100);
    room1.setNewAgeLimit(2);
    room2.setNewAgeLimit(10);
    room3.setNewAgeLimit(10000);
    ASSERT_THROWS(ScaryRoomIllegalAgeLimit, room3.setNewAgeLimit(-1));

}

void SCRprint(){
    ScaryRoom room((char*)"room",30,2,20,10,2);
    ScaryRoom room1((char*)"room1",40,3,10,10,10);
    ScaryRoom room4((char*)"room4",50,8,1,1,1);
    ScaryRoom room5((char*)"room5",31,6,6,6,6);


    ASSERT_PRINT("Scary room: room (30/2/20/10)",room);
    ASSERT_PRINT("Scary room: room1 (40/3/10/10)",room1);
    ASSERT_PRINT("Scary room: room4 (50/8/1/1)",room4);
    ASSERT_PRINT("Scary room: room5 (31/6/6/6)",room5);
}

int main(){
    RUN_TEST(SCRbasic);
    RUN_TEST(SCRageLimit);
    RUN_TEST(SCRprint);
}
