
#include "ScaryRoom.h"
#include "Exceptions.h"

namespace mtm{
namespace escaperoom{
ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level,
                     const int &maxParticipants, const int &ageLimit,
                     const int &numOfScaryEnigmas) :
        EscapeRoomWrapper(name, escapeTime, level, maxParticipants) {
    if (ageLimit<=0)
        throw ScaryRoomIllegalAgeLimit();
    AgeLimit=ageLimit;
    NumOfScaryEnigmas=numOfScaryEnigmas;
}

void ScaryRoom::incNumberOfScaryEnigmas() {
    NumOfScaryEnigmas++;
}
int ScaryRoom::getAgeLimit() const {
    return AgeLimit;
}

void ScaryRoom::setNewAgeLimit(const int &ageLimit) {
    if(ageLimit<=0)
        throw ScaryRoomIllegalAgeLimit();
    AgeLimit=ageLimit;
}

std::ostream& operator<<(std::ostream &output, const ScaryRoom& room){
    return output << "Scary Room: " << room.getName() << " (" <<
                room.getMaxTime() << "/" << room.level() << "/" <<
                room.getMaxParticipants() << "/"<< room.getAgeLimit()<< ")";
}


    ScaryRoom& ScaryRoom::operator=(const ScaryRoom room){
        EscapeRoomWrapper::operator=(room);
        this->AgeLimit=room.AgeLimit;
        this->NumOfScaryEnigmas=room.NumOfScaryEnigmas;
        return *this;
    }
}
}