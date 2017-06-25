
#include "ScaryRoom.h"


namespace mtm{
namespace escaperoom{
ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level,
                     const int &maxParticipants, const int &ageLimit,
                     const int &numOfScaryEnigmas): {
    EscapeRoom room=escapeRoomCreate(name,escapeTime,maxParticipants,level);
    if (room==NULL)
        throw EscapeRoomMemoryProblemException();
    escapeRoom=room;
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
    return output << "Scary room: " << roomGetName(room.escapeRoom) << " (" <<
                roomGetMaxTime(room.escapeRoom) << "/" <<
                getLevel(room.escapeRoom) << "/" <<
                roomGetMaxParticipants(room.escapeRoom) << "/"<<
                room.getAgeLimit()<< ")";
}

}
}