

#ifndef EX4_WET_SCARYROOM_H
#define EX4_WET_SCARYROOM_H

#include "EscapeRoomWrapper.h"
#include "Exceptions.h"



namespace mtm{
    namespace escaperoom{
class ScaryRoom : EscapeRoom {
    EscapeRoom escapeRoom;
    int AgeLimit;
    int NumOfScaryEnigmas;
public:
    /*!
     * constructor to the class
     recieves same parameters of EscapeRoom and also two more
     * @param ageLimit age restriction parameter
     * @param numOfScaryEnigmas the number of scary enigmas in the room
     */
    ScaryRoom(char* name, const int& escapeTime, const int& level,
              const int& maxParticipants, const int& ageLimit,
              const int& numOfScaryEnigmas);

    void setNewAgeLimit(const int& ageLimit);

    void incNumberOfScaryEnigmas();

    int getAgeLimit() const ;

    std::ostream& operator<<(std::ostream& output, const ScaryRoom& room);
};
}
}
#endif //EX4_WET_SCARYROOM_H
