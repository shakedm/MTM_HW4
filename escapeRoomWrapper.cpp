
#include "EscapeRoomWrapper.h"



namespace mtm {
namespace escaperoom{

    EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &escapeTime,
                      const int &level, const int &maxParticipants) {
        this->name=name;//is this correct?
        this->level=level;
        this->maxTime=escapeTime;
        this->maxParticipants=maxParticipants;
        this->avgrate=0;
        this->votes=0;
    }
    EscapeRoomWrapper::EscapeRoomWrapper(char *name, const int &level) {
        this->name=name;
        this->level=level;
        this->maxTime=60;
        this->maxParticipants=6;
        this->votes=0;
        this->avgrate=0;
    }
    EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper &room) {
        this->avgrate=0;
        this->votes=0;
        this->maxParticipants=room.maxParticipants;
        this->maxTime=room.maxTime;
        this->name= room.name;
    }
    int EscapeRoomWrapper::getMaxParticipants() const {
        return this->maxParticipants;
    }
    int EscapeRoomWrapper::getMaxTime() const {
        return this->maxTime;
    }
    double EscapeRoomWrapper::getRate() const {
        return this->avgrate;
    }
    std::string EscapeRoomWrapper::getName() const {
        return this->name;
    }

}
}