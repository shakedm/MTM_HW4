
#include "EscapeRoomWrapper.h"
#include "Exceptions.h"


namespace mtm {
namespace escaperoom{

    EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &escapeTime,
                      const int &level, const int &maxParticipants){
        EscapeRoom room=escapeRoomCreate(name,escapeTime,maxParticipants,level);
        if(room==NULL){
            throw EscapeRoomMemoryProblemException();
        }
        escaperoom=room;
    }

    EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &level){
        EscapeRoom room=escapeRoomCreate(name,60,6,level);
        if(!room){
            throw EscapeRoomMemoryProblemException();
        }
        escaperoom=room;
    }

    EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper &room) {
        EscapeRoom room1 =escapeRoomCopy(room.escaperoom);
        if(!room1){
            throw EscapeRoomMemoryProblemException();
        }
        this->escaperoom=room1;
    }

    int EscapeRoomWrapper::getMaxParticipants() const {
        return (roomGetMaxParticipants(escaperoom));
    }

    int EscapeRoomWrapper::getMaxTime() const {
        return roomGetMaxTime(escaperoom);
    }

    double EscapeRoomWrapper::getRate() const {
        return roomGetRate(escaperoom);
    }
    int EscapeRoomWrapper::level() const{
        return getLevel(escaperoom);
    }

    std::string EscapeRoomWrapper::getName() const {
        char* name_copy = roomGetName(escaperoom);
        string name(name_copy);
        free(name_copy);
        return name;
    }

    //     "<name> (<maxTime>/<level>/<maxParticipants>)"
    std::ostream& operator<<(std::ostream& output,
                                    const EscapeRoomWrapper& room){
        return output << room.getName() << " (" <<
                         roomGetMaxTime(room.escaperoom)
                      << "/" << getLevel(room.escaperoom) << "/" <<
                         roomGetMaxParticipants(room.escaperoom) << ")";
    }

    double EscapeRoomWrapper::calculatePower(const int& maxTime, const int& level,
                          const int& maxParticipants){
        double power;
        power = level*maxTime;
        power /= maxParticipants;
        return power;
    }

    bool EscapeRoomWrapper::operator==(const EscapeRoomWrapper& room) const{
        return areEqualRooms(this->escaperoom,room.escaperoom);
    }

    bool EscapeRoomWrapper::operator!=(const EscapeRoomWrapper& room) const{
        return !(*this==room);
    }

    bool EscapeRoomWrapper::operator<(const EscapeRoomWrapper& room) const{
        return isBiggerRoom(room.escaperoom,this->escaperoom);
    }

    bool EscapeRoomWrapper::operator>(const EscapeRoomWrapper& room) const{
        return isBiggerRoom(this->escaperoom,room.escaperoom);
    }
    void EscapeRoomWrapper::rate(const int& newRate) const{
        updateRate(escaperoom,newRate);
    }
    EscapeRoomWrapper::~EscapeRoomWrapper(){
        escapeRoomDestroy(escaperoom);
    }
    EscapeRoomWrapper & EscapeRoomWrapper::operator=(const EscapeRoomWrapper&
    room){
        EscapeRoom room1=escapeRoomCopy(room.escaperoom);
        if (!room1)
            throw EscapeRoomMemoryProblemException();
        escapeRoomDestroy(this->escaperoom);
        this->escaperoom=room1;
        return *this;
    }
    void EscapeRoomWrapper::addEnigma(const Enigma& enigma){
        roomEnigma.push_back(enigma);
    }
    void EscapeRoomWrapper::removeEnigma(const Enigma& enigma){
        if (roomEnigma.size()==0)
            throw EscapeRoomNoEnigmasException();
        for (int i = 0; i < (int)roomEnigma.size() ; ++i) {
            if (enigma==roomEnigma.at((unsigned int)i)){
                roomEnigma.erase(roomEnigma.begin()+i);
                return;
            }
        }
        throw EscapeRoomEnigmaNotFoundException();
    }
    Enigma EscapeRoomWrapper::getHardestEnigma() {

        if(roomEnigma.size()==0)
            throw EscapeRoomNoEnigmasException();
        Enigma hardest=roomEnigma.front();
        for (unsigned int i = 1; i < roomEnigma.size(); ++i) {

            if(roomEnigma.at(i) > hardest)
                hardest=roomEnigma.at(i);
        }
        return hardest;
    }
    std::vector<Enigma>& EscapeRoomWrapper::getAllEnigmas(){
        return roomEnigma;
    }
}
}