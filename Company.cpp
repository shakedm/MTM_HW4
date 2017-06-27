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
            EscapeRoomWrapper* room=new EscapeRoomWrapper(name, escapeTime,
                                                       level, maxParticipants);
            try {
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

                ScaryRoom* new_room= new ScaryRoom(name, escapeTime,
                                                  level, maxParticipants,
                                                  ageLimit, numOfScaryEnigmas);
                rooms.insert((EscapeRoomWrapper*)new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }


        } //Shaked

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {
            try {


                KidsRoom* new_room=new KidsRoom(name, escapeTime, level,
                                                maxParticipants, ageLimit);
                rooms.insert((EscapeRoomWrapper*)new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }

        } //Shaked

        set<EscapeRoomWrapper*> Company::getAllRooms() const {} //Adi

        void Company::removeRoom(const EscapeRoomWrapper &room) {


        } //Adi

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {
            if (rooms.end() == this->rooms.find(room))
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