
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

    }

    EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &level){
        EscapeRoom room=escapeRoomCreate(name,60,6,level);
        if(!room){
            throw EscapeRoomMemoryProblemException();
        }
    }

    EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper &room) {
        EscapeRoom room1 =escapeRoomCopy(room.escaperoom);
        if(!room1){
            throw EscapeRoomMemoryProblemException();
        }
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
        string name(roomGetName(escaperoom));
        return name;
    }

    //     "<name> (<maxTime>/<level>/<maxParticipants>)"
    friend std::ostream& operator<<(std::ostream& output,
                                    const EscapeRoomWrapper& room){
        return output << roomGetName(room.escaperoom) << " (" <<
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
    virtual EscapeRoomWrapper::~EscapeRoomWrapper(){
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

}
}