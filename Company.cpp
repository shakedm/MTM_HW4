#include "Company.h"
#include <exception>
#include <iostream>
using  namespace std;


namespace mtm{
    namespace escaperoom {

        Company::Company(string name, string phoneNumber) {}

        Company::Company(const Company &company) {}

        Company& Company::operator=(const Company &company) {} //Adi

        void Company::createRoom(char *name, const int &escapeTime,
                                 const int &level,
                                 const int &maxParticipants) {
            EscapeRoomWrapper room(name, escapeTime, level, maxParticipants);
            try {
                rooms.insert(&room);
            } catch (exception& exception){
                throw
            }
        }

        void Company::createScaryRoom(char *name, const int &escapeTime,
                                      const int &level,
                                      const int &maxParticipants,
                                      const int &ageLimit,
                                      const int &numOfScaryEnigmas) {

            try {

                ScaryRoom new_room(name, escapeTime, level, maxParticipants,
                                   ageLimit,
                                   numOfScaryEnigmas);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }
            this->rooms.insert(&new_room);

        } //Shaked

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {
            try {


                KidsRoom new_room(name, escapeTime, level, maxParticipants,
                                  ageLimit);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }
            this->rooms.insert(&new_room);
        } //Shaked

        set<EscapeRoomWrapper*> Company::getAllRooms() const {} //Adi

        void Company::removeRoom(const EscapeRoomWrapper &room) {
            set<EscapeRoomWrapper*>::iterator iterator= rooms.find(room);

        } //Adi

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {
            if (rooms.find(room)==rooms.end())
                throw CompanyRoomNotFoundException();
            room.addEnigma(enigma);
        } //Shaked

        void Company::removeEnigma(const EscapeRoomWrapper &room,
                                   const Enigma &enigma) {
            if (rooms.find(room)==rooms.end())
                throw CompanyRoomNotFoundException();
            try {

                room.removeEnigma(enigma);
            } catch (EscapeRoomNoEnigmasException){
                throw CompanyRoomHasNoEnigmasException();
            } catch (EscapeRoomEnigmaNotFoundException){
                throw CompanyRoomEnigmaElementNotFoundException();
            }
        } //Shaked

        void Company::addItem(const EscapeRoomWrapper &room,
                              const Enigma &enigma, const string &element) {} //Adi

        void Company::removeItem(const EscapeRoomWrapper &room,
                                 const Enigma &enigma, const string &element) {} //Adi

        set<EscapeRoomWrapper*> Company::getAllRoomsByType(
                RoomType type) const {
            for (it=rooms.begin();  it!=rooms.end() ; ++it) {
                if(it==type){

                }
            }
        } //Shaked

        EscapeRoomWrapper Company::getRoomByName(const string &name) const {} //Adi

        std::ostream& Company::operator<<(std::ostream &output,
                                          const Company &company) {} //Shaked

        Company::~Company() {}
    }
}