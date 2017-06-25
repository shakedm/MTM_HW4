
#include "ScaryRoom.h"


namespace mtm{
namespace escaperoom{
ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level,
                     const int &maxParticipants, const int &ageLimit,
                     const int &numOfScaryEnigmas) :
        EscapeRoomWrapper(name, escapeTime, level, maxParticipants) {
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
    AgeLimit=ageLimit;
}

std::ostream& ScaryRoom::operator<<(std::ostream &output,
                                    const ScaryRoom &room) {
    return output << "Scary room: " << getName() << " (" <<
                getMaxTime() << "/" << level() << "/" <<
                getMaxParticipants() << "/"<< room.getAgeLimit()<< ")";
}

}
}