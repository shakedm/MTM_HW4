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
            try {
                EscapeRoomWrapper *room = new EscapeRoomWrapper(name,
                                                                escapeTime,
                                                                level,
                                                                maxParticipants);
                rooms.insert(room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
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
                this->rooms.insert(&new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }


        } //Shaked

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {
            try {


                KidsRoom new_room(name, escapeTime, level, maxParticipants,
                                  ageLimit);
                this->rooms.insert(&new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }

        } //Shaked

        set<EscapeRoomWrapper*> Company::getAllRooms() const {
            return this->rooms;
        } //Adi

        void Company::removeRoom(const EscapeRoomWrapper& room) {
            bool found = false;
            for (set<EscapeRoomWrapper*>::iterator it = rooms.begin();
                 it != rooms.end(); ++it) {
                if ((*it)->getName() == room.getName()){
                    rooms.erase(*it);
                    found = true;
                    break;
                }//given: no two rooms of a company have the same name.
            }
            if (!found){
                throw CompanyRoomNotFoundException();
            }

        } //Adi

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {
            bool found = false;
            EscapeRoomWrapper* addTo = NULL;
            for (set<EscapeRoomWrapper*>::iterator it = rooms.begin();
                 it != rooms.end(); ++it) {
                if ((*it)->getName() == room.getName()){
                    addTo = *it;
                    found = true;
                    break;
                }//given: no two rooms of a company have the same name.
            }
            if (!found){
                throw CompanyRoomNotFoundException();
            }
            addTo->addEnigma(enigma);
        } //Shaked

        void Company::removeEnigma(const EscapeRoomWrapper &room,
                                   const Enigma &enigma) {
            bool found = false;
            EscapeRoomWrapper* removeFrom = NULL;
            for (set<EscapeRoomWrapper*>::iterator it = rooms.begin();
                 it != rooms.end(); ++it) {
                if ((*it)->getName() == room.getName()){
                    removeFrom = *it;
                    found = true;
                    break;
                }//given: no two rooms of a company have the same name.
            }
            if (!found){
                throw CompanyRoomNotFoundException();
            }
            try {
                removeFrom->removeEnigma(enigma);
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
            set<EscapeRoomWrapper*> filter; //could be a problem of allocating
            //memory
            for (set<EscapeRoomWrapper*>::iterator it=rooms.begin();
                 it!=rooms.end() ; ++it) {
                if(getRoomType(*it)==type){
                    filter.insert(*it);
                }
            }
            return filter;
        } //Shaked


        EscapeRoomWrapper Company::getRoomByName(const string &name) const {} //Adi

        // Prints the data of the company in the following format:
        //
        //     "<CompanyName> : <PhoneNumber>\n
        //      -<RoomName>
        //      -<RoomName> …"
        //
        // @param output : the output stream to which the data is printed.
        // @param company : the company whose data is printed.
        std::ostream& operator<<(std::ostream &output,
                                          const Company &company) {
            output <<company.name<< ":" <<company.phoneNumber<<endl;
            for (set<EscapeRoomWrapper*>::iterator it=rooms.begin() ;
                    it!= rooms.end() ;++it){
                output<< *(*it)<<endl;
            }
            return output<< endl;

        } //Shaked

        Company::~Company() {}

        static RoomType Company::getRoomType(const EscapeRoomWrapper* room) const {
            ScaryRoom* a= dynamic_cast<ScaryRoom*>(room);
            if(a!=NULL)
                return SCARY_ROOM;
            KidsRoom* b= dynamic_cast<KidsRoom*>(room);
            if(b!=NULL)
                return KIDS_ROOM;
            return BASE_ROOM;
        }
    }
}