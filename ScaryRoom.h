

#ifndef EX4_WET_SCARYROOM_H
#define EX4_WET_SCARYROOM_H

#include "EscapeRoomWrapper.h"
using mtm::escaperoom::EscapeRoomWrapper;

class ScaryRoom : EscapeRoom {
    int ageLimit;
    int numOfScaryEnigmas;
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
};


#endif //EX4_WET_SCARYROOM_H
