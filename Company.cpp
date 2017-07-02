#include "Company.h"
#include <exception>
#include <algorithm>
using  namespace std;


namespace mtm{
    namespace escaperoom {

        Company::Company(string name, string phoneNumber) :
                name(name),
                phoneNumber(phoneNumber){
            //set<EscapeRoomWrapper*> *set1 = new set<EscapeRoomWrapper*>();
            rooms = set<EscapeRoomWrapper*>();
        }

        Company::Company(const Company &company) :
                name (company.name),
                phoneNumber(company.phoneNumber){
            set<EscapeRoomWrapper*> set1 = set<EscapeRoomWrapper*>();
            rooms = set1;
            for (set<EscapeRoomWrapper*>::iterator it = company.rooms.begin();
                 it != company.rooms.end(); ++it) {
                EscapeRoomWrapper* current = *it;
                EscapeRoomWrapper* copy = (*current).clone();
                rooms.insert(copy);
            }//given: no two rooms of a company have the same name.
        }

        bool Company::operator==(const Company &company) const {
            return phoneNumber == company.phoneNumber &&
                   name == company.name;
        }

        bool Company::operator!=(const Company &company) const {
            return !(*this == company);
        }

        Company& Company::operator=(const Company &company) {
            if (*this == company){
                return *this;
            }
            name = company.name;
            phoneNumber = company.phoneNumber;
            set<EscapeRoomWrapper*> set1 = set<EscapeRoomWrapper*>();
            rooms = set1;
            for (set<EscapeRoomWrapper*>::iterator it = company.rooms.begin();
                 it != company.rooms.end(); ++it) {
                EscapeRoomWrapper* current = *it;
                EscapeRoomWrapper* copy = (*current).clone();
                rooms.insert(copy);
            }
            return *this;
        }

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

                ScaryRoom *new_room = new ScaryRoom(name, escapeTime, level,
                                                    maxParticipants, ageLimit,
                                                    numOfScaryEnigmas);
                rooms.insert((EscapeRoomWrapper*)new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }


        }

        void Company::createKidsRoom(char *name, const int &escapeTime,
                                     const int &level,
                                     const int &maxParticipants,
                                     const int &ageLimit) {
            try {


                KidsRoom *new_room = new KidsRoom(name, escapeTime, level,
                                                  maxParticipants, ageLimit);
                this->rooms.insert((EscapeRoomWrapper*)new_room);
            } catch (EscapeRoomMemoryProblemException){
                throw CompanyMemoryProblemException();
            }

        }

        set<EscapeRoomWrapper*> Company::getAllRooms() const {
            return this->rooms;
        } //Adi

        void Company::removeRoom(const EscapeRoomWrapper& room) {
            try {
                EscapeRoomWrapper* roomPtr = getRoomByName(room.getName());
                if ((*roomPtr) != room){
                    throw CompanyRoomNotFoundException();
                }
                delete(roomPtr);
                rooms.erase(roomPtr);
            } catch (CompanyRoomNotFoundException){
                throw CompanyRoomNotFoundException();
            }

        }

        void Company::addEnigma(const EscapeRoomWrapper &room,
                                const Enigma &enigma) {
            try {
                EscapeRoomWrapper* addTo = getRoomByName(room.getName());
                if ((*addTo) != room){
                    throw CompanyRoomNotFoundException();
                }
                addTo->addEnigma(enigma);
            } catch (CompanyRoomNotFoundException){
                throw CompanyRoomNotFoundException();
            }
        }

        void Company::removeEnigma(const EscapeRoomWrapper &room,
                                   const Enigma &enigma) {
            try {
                EscapeRoomWrapper* removeFrom = getRoomByName(room.getName());
                if ((*removeFrom) != room){
                    throw CompanyRoomNotFoundException();
                }
                removeFrom->removeEnigma(enigma);
            } catch (EscapeRoomEnigmaNotFoundException) {
                throw CompanyRoomEnigmaNotFoundException();
            }catch (EscapeRoomNoEnigmasException){
                throw CompanyRoomHasNoEnigmasException();
            }
             catch (CompanyRoomNotFoundException){
                throw CompanyRoomNotFoundException();
            }
        }

        void Company::addItem(const EscapeRoomWrapper &room,
                              const Enigma &enigma, const string &element) {
            EscapeRoomWrapper* wanted = NULL;
            try{
                wanted = getRoomByName(room.getName());
                if ((*wanted) != room){
                    throw CompanyRoomNotFoundException();
                }
            } catch (CompanyRoomNotFoundException){
                throw CompanyRoomNotFoundException();
            }
            vector<Enigma>* enigmas = &(wanted->getAllEnigmas());
            int size = (int)enigmas->size();
            unsigned int i;
            for (i = 0; i < size; ++i) {
                if (enigmas->at(i) == enigma){
                    break;
                }
            }
            if(i != size){
                (enigmas->at(i)).addElement(element);
            } else {
                throw CompanyRoomEnigmaNotFoundException();
            }
        }

        void Company::removeItem(const EscapeRoomWrapper &room,
                                 const Enigma &enigma, const string &element) {
            EscapeRoomWrapper* removeFromRoom = NULL;
            try{
                removeFromRoom = getRoomByName(room.getName());
                if ((*removeFromRoom) != room){
                    throw CompanyRoomNotFoundException();
                }
            } catch (CompanyRoomNotFoundException){
                throw CompanyRoomNotFoundException();
            }
            vector<Enigma> enigmas;
            enigmas = (*removeFromRoom).getAllEnigmas();
            vector<Enigma>::iterator removeFromEnigma = find(enigmas.begin(),
                                                      enigmas.end(), enigma);
            if(removeFromEnigma != enigmas.end()){
                try {
                    removeFromEnigma->removeElement(element);
                } catch (EnigmaElementNotFoundException){
                    throw CompanyRoomEnigmaElementNotFoundException();
                } catch (EnigmaNoElementsException){
                    throw CompanyRoomEnigmaHasNoElementsException();
                }
            } else {
                throw CompanyRoomEnigmaNotFoundException();
            }
        }

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
        }


        EscapeRoomWrapper* Company::getRoomByName(const string &name) const {
            bool found = false;
            EscapeRoomWrapper* wanted = NULL;
            for (set<EscapeRoomWrapper*>::iterator it = rooms.begin();
                 it != rooms.end(); ++it) {
                if ((*it)->getName() == name){
                    wanted = *it;
                    found = true;
                    break;
                }//given: no two rooms of a company have the same name.
            }
            if (!found){
                throw CompanyRoomNotFoundException();
            }
            return wanted;
        }

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
            for (set<EscapeRoomWrapper*>::iterator it=company.rooms.begin() ;
                    it!= company.rooms.end() ;++it){
                ScaryRoom* scaryRoom= dynamic_cast<ScaryRoom*> (*it);
                if (scaryRoom!= NULL){
                    output<< *scaryRoom <<endl;
                } else{
                    KidsRoom* kidsRoom= dynamic_cast<KidsRoom*>(*it);
                    if (kidsRoom!=NULL){
                        output<<*kidsRoom<< endl;
                    } else{
                        output<< *(*it) <<endl;
                    }
                }

            }
            return output<< endl;

        }

        Company::~Company() {
            for (set<EscapeRoomWrapper*>::iterator it = rooms.begin();
                 it != rooms.end(); ++it) {
                delete (*it);
            }
            //delete (*this).rooms;
        }

        RoomType Company::getRoomType(const EscapeRoomWrapper* room) const {
            const ScaryRoom* a= dynamic_cast<const ScaryRoom*>(room);
            if(a!=NULL)
                return SCARY_ROOM;
            const KidsRoom* b= dynamic_cast<const KidsRoom*>(room);
            if(b!=NULL)
                return KIDS_ROOM;
            return BASE_ROOM;
        }
    }
}