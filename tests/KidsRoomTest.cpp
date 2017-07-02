#include "../KidsRoom.h"
#include "../mtmtest.h"



using namespace mtm::escaperoom;

static void KDSRbasic(){
    KidsRoom room((char* )"room",40,2,3,4);
    KidsRoom room1((char* )"room1",90,10,10,10);

    ASSERT_EQUALS("room", room.getName());
    ASSERT_EQUALS("room1",room1.getName());
    ASSERT_EQUALS(10, room1.getAgeLimit());
    ASSERT_EQUALS(4,room.getAgeLimit());
}
static void KDSRoperator(){
    KidsRoom room((char*)"room",30,2,2,2);
    KidsRoom room1((char*)"room1",90,10,10,10);
    KidsRoom room2((char*)"room2",50,5,5,5);

    ASSERT_EQUALS("room",room.getName());
    room=room1;
    ASSERT_EQUALS("room1",room.getName());
    ASSERT_EQUALS("room1",room1.getName());
    ASSERT_EQUALS(90,room.getMaxTime());
    ASSERT_EQUALS(90,room1.getMaxTime());
    ASSERT_EQUALS(10,room.getMaxParticipants());
    ASSERT_EQUALS(10,room1.getMaxParticipants());
    ASSERT_EQUALS(10,room.getAgeLimit());
    ASSERT_EQUALS(10,room1.getAgeLimit());
    ASSERT_EQUALS("room2",room2.getName());
    ASSERT_EQUALS(50,room2.getMaxTime());
    ASSERT_EQUALS(5,room2.getAgeLimit());

}

static void KDSsetAgeLimit(){
    KidsRoom room((char*)"room",30,2,2,2);
    KidsRoom room1((char*)"room1",90,10,10,10);
    KidsRoom room2((char*)"room2",50,5,5,5);

    ASSERT_EQUALS(2,room.getAgeLimit());
    ASSERT_EQUALS(10,room1.getAgeLimit());
    ASSERT_EQUALS(5,room2.getAgeLimit());
    ASSERT_NO_THROW(room.setNewAgeLimit(100));
    ASSERT_NO_THROW(room1.setNewAgeLimit(102));
    ASSERT_NO_THROW(room2.setNewAgeLimit(12345678));
    ASSERT_EQUALS(100,room.getAgeLimit());
    ASSERT_EQUALS(102,room1.getAgeLimit());
    ASSERT_EQUALS(12345678,room2.getAgeLimit());
    room=room2;
    ASSERT_EQUALS(12345678,room.getAgeLimit());
}

static void KDSprint(){
    KidsRoom room((char*)"room",30,2,2,2);
    KidsRoom room1((char*)"room1",90,10,10,10);
    KidsRoom room2((char*)"room2",50,5,5,5);
    KidsRoom room3((char*)"room3",40,3,4,55);

    ASSERT_PRINT("Kids Room: room (30/2/2/2)",room);
    ASSERT_PRINT("Kids Room: room1 (90/10/10/10)",room1);
    ASSERT_PRINT("Kids Room: room2 (50/5/5/5)",room2);
    ASSERT_PRINT("Kids Room: room3 (40/3/4/55)",room3);
}


int mainKids(){
    RUN_TEST(KDSRbasic);
    RUN_TEST(KDSRoperator);
    RUN_TEST(KDSsetAgeLimit);
    RUN_TEST(KDSprint);
}