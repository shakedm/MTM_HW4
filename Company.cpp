#include "Company.h"

namespace mtm{
    namespace escaperoom {

        Company::Company(string name, string phoneNumber) {}

        Company::Company(const Company &company) {}

        Company& Company::operator=(const Company &company) {} //Adi

        void Company::createRoom(char *name, const int &escapeTime,
                                 const int &level,
                                 const int &maxParticipants) {} //Adi

        void Company::createScaryRoom(char *name, const int &escapeTime,
                                      const int &level,
                                      const int &maxParticipants,
                                      const int &ageLimit,
                                      const int &numOfScaryEnigmas) {} //Shaked

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {} //Shaked

        set<EscapeRoomWrapper*> Company::getAllRooms() const {} //Adi

        void Company::removeRoom(const EscapeRoomWrapper &room) {} //Adi

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {} //Shaked

        void Company::removeEnigma(const EscapeRoomWrapper &room,
                                   const Enigma &enigma) {} //Shaked

        void Company::addItem(const EscapeRoomWrapper &room,
                              const Enigma &enigma, const string &element) {} //Adi

        void Company::removeItem(const EscapeRoomWrapper &room,
                                 const Enigma &enigma, const string &element) {} //Adi

        set<EscapeRoomWrapper*> Company::getAllRoomsByType(
                RoomType type) const {} //Shaked

        EscapeRoomWrapper Company::getRoomByName(const string &name) const {} //Adi

        std::ostream& Company::operator<<(std::ostream &output,
                                          const Company &company) {} //Shaked

        Company::~Company() {}
    }
}