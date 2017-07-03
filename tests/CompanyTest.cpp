#include "../Company.h"
#include "../mtmtest.h"
#include "../Exceptions.h"

using namespace mtm::escaperoom;
using std::cout;
using std::endl;

static void CompanyBasic(){
    Company company("1","054-45959151");
    ASSERT_NO_THROW(company.createRoom((char*)"room1",30,2,3));
    ASSERT_NO_THROW(company.createKidsRoom((char*)"kids1",40,2,3,18));
    ASSERT_NO_THROW(company.createScaryRoom((char*)"scary1",30,3,2,40,20));
    ASSERT_NO_THROW(company.createScaryRoom((char*)"scary2",40,4,8,12,1));
    ASSERT_THROWS(CompanyRoomNotFoundException,company.getRoomByName("room2"));
    ASSERT_NO_THROW(company.getRoomByName("room1"));
    Enigma enigma("riddle", HARD_ENIGMA);
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("kids1"),enigma));
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("scary1"),enigma));
    ASSERT_NO_THROW(company.removeEnigma(*company.getRoomByName("kids1"),enigma));
    ASSERT_THROWS(CompanyRoomHasNoEnigmasException,
                  company.removeEnigma(*company.getRoomByName("kids1"),enigma));
}

static void CompanyOperators(){
    Company company("2","911");
    company.createScaryRoom((char*)"scary1",40,2,3,2,2);
    company.createScaryRoom((char*)"scary2",50,6,6,6,6);
    company.createRoom((char*)"room",40,5,6);
    company.createRoom((char*)"room2",90,8,6);
    Company company1=company;
    ASSERT_NO_THROW(company1.removeRoom(*company1.getRoomByName("scary1")));
    ASSERT_NO_THROW(company1.removeRoom(*company1.getRoomByName("room2")));
    company.removeRoom(*company.getRoomByName("room"));
    ASSERT_NO_THROW(*company1.getRoomByName("room"));
    company = company1;
    ASSERT_NOT_EQUAL(company.getAllRooms(),company1.getAllRooms());
}
static void CompanyCopy(){
    Company company("3","100");
    Company company1(company);
    ASSERT_EQUALS(company,company1);
    ASSERT_EQUALS(company.getAllRooms(),company1.getAllRooms());
    company.createRoom((char*)"room",40,6,8);
    Company company2(company);
    ASSERT_EQUALS(company,company2);
   // ASSERT_EQUALS(company.getAllRooms(),company2.getAllRooms());
    company.removeRoom(*company.getRoomByName("room"));
    ASSERT_NO_THROW(company2.getRoomByName("room"));

}

static void CompanyEnigmas(){
    Company company("4","100");
    Enigma enigma("r", MEDIUM_ENIGMA);
    Enigma enigma1("q", HARD_ENIGMA);
    company.createRoom((char*)"room",60,6,8);
    company.createRoom((char*)"room1",90,4,3);
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room"),enigma));
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room1"),enigma));
    ASSERT_NO_THROW(company.removeEnigma(*company.getRoomByName("room"),enigma));
    Enigma enigma2("s",EASY_ENIGMA);
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room"),enigma2));
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room"),enigma1));
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room"),enigma));
    Company company1(company);
    ASSERT_NO_THROW(company.addEnigma(*company.getRoomByName("room1"),enigma1));
    ASSERT_NO_THROW(company1.addEnigma(*company1.getRoomByName("room1"),enigma2)
                    );
    ASSERT_THROWS(CompanyRoomEnigmaNotFoundException,
                company.removeEnigma(*company.getRoomByName("room1"),enigma2));
    ASSERT_THROWS(CompanyRoomEnigmaNotFoundException,
                company1.removeEnigma(*company1.getRoomByName("room1"),enigma1));
    company1.createRoom((char*)"room10",90,5,4);
    ASSERT_THROWS(CompanyRoomHasNoEnigmasException,
                company1.removeEnigma(*company1.getRoomByName("room10"),enigma));


}

static void CompanyItem(){
    Company company("4","100");
    Enigma enigma("r",EASY_ENIGMA);
    Enigma enigma1("q",HARD_ENIGMA);
    company.createRoom((char*)"room",60,6,8);
    company.createRoom((char*)"room1",90,4,3);
    company.addEnigma(*company.getRoomByName("room1"),enigma);
    ASSERT_THROWS(CompanyRoomNotFoundException,company.addItem
            (*company.getRoomByName("room2"),enigma,"item"));
    ASSERT_THROWS(CompanyRoomEnigmaNotFoundException,company.addItem
            (*company.getRoomByName("room"),enigma,"item"));
    ASSERT_NO_THROW(company.addItem(*company.getRoomByName("room1"),
                                    enigma,"item"));
    ASSERT_THROWS(CompanyRoomNotFoundException,company.removeItem
            (*company.getRoomByName("room2"),enigma,"item"));
    ASSERT_THROWS(CompanyRoomEnigmaNotFoundException,company.removeItem
            (*company.getRoomByName("room"),enigma1,"item"));
    company.addEnigma(*company.getRoomByName("room"), enigma1);
    ASSERT_THROWS(CompanyRoomEnigmaHasNoElementsException,company.removeItem
            (*company.getRoomByName("room"),enigma1,"item"));
    ASSERT_THROWS(CompanyRoomEnigmaElementNotFoundException,company.removeItem
            (*company.getRoomByName("room1"),enigma,"item1"));
    ASSERT_NO_THROW(company.removeItem(*company.getRoomByName("room1"),
                                       enigma,"item"));
    ASSERT_THROWS(CompanyRoomEnigmaHasNoElementsException ,company.removeItem
            (*company.getRoomByName("room1"),enigma,"item"));
}

static void CompanyPrint(){
    Company company("4","100");
    company.createRoom((char*)"room",40,3,3);
    company.createScaryRoom((char*)"room1",90,10,10,10,10);
    company.createKidsRoom((char*)"room2",80,5,5,6);
    Company company1(company);
    company.removeRoom(*company.getRoomByName("room"));
    company.removeRoom(*company.getRoomByName("room1"));
    ASSERT_PRINT("4 : 100\nKids Room: room2 (80/5/5/6)\n\n",company);
    company1.removeRoom(*company1.getRoomByName("room"));
    company1.removeRoom((*company1.getRoomByName("room2")));
    ASSERT_PRINT("4 : 100\nScary Room: room1 (90/10/10/10)\n\n",company1);
    company.removeRoom(*company.getRoomByName("room2"));
    company.createRoom((char*)"room",40,3,3);
    ASSERT_PRINT("4 : 100\nroom (40/3/3)\n\n",company);

}

int main(){
    RUN_TEST(CompanyPrint);
    RUN_TEST(CompanyBasic);
    RUN_TEST(CompanyOperators);
    RUN_TEST(CompanyEnigmas);
    RUN_TEST(CompanyItem);
    RUN_TEST(CompanyCopy);
    return 0;
}