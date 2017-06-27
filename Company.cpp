#include "Company.h"

namespace mtm{
    namespace escaperoom {

        Company::Company(string name, string phoneNumber) {}

        Company::Company(const Company &company) {}

        Company& Company::operator=(const Company &company) {}

        void Company::createRoom(char *name, const int &escapeTime,
                                 const int &level,
                                 const int &maxParticipants) {}

        void Company::createScaryRoom(char *name, const int &escapeTime,
                                      const int &level,
                                      const int &maxParticipants,
                                      const int &ageLimit,
                                      const int &numOfScaryEnigmas) {}

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {}

        set<EscapeRoomWrapper*> Company::getAllRooms() const {}

        void Company::removeRoom(const EscapeRoomWrapper &room) {}

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {}

        void Company::removeEnigma(const EscapeRoomWrapper &room,
                                   const Enigma &enigma) {}

        void Company::addItem(const EscapeRoomWrapper &room,
                              const Enigma &enigma, const string &element) {}

        void Company::removeItem(const EscapeRoomWrapper &room,
                                 const Enigma &enigma, const string &element) {}

        set<EscapeRoomWrapper*> Company::getAllRoomsByType(
                RoomType type) const {}

        EscapeRoomWrapper Company::getRoomByName(const string &name) const {}

        std::ostream& Company::operator<<(std::ostream &output,
                                          const Company &company) {}

        Company::~Company() {}
    }
}