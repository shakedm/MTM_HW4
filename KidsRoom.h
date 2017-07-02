#ifndef EX4_WET_KIDSROOM_H
#define EX4_WET_KIDSROOM_H

#include "EscapeRoomWrapper.h"
#include "Exceptions.h"

#define MIN 0

namespace mtm {
    namespace escaperoom {
        class KidsRoom : public EscapeRoomWrapper {
            int AgeLimit; //the max age allowed in the room.

        public:

            /*!
             * kids room c'tor. constructs a new escape room with an age limit
             * field - which is the max age allowed in the room.
             * @param name - the room's name.
             * @param escapeTime - the max time to escape.
             * @param level  - the room's level.
             * @param maxParticipants - the max num of participents per room.
             * @param ageLimit - the max age for a participents in the room.
             */
            KidsRoom(char* name, const int& escapeTime, const int& level,
                     const int& maxParticipants, const int& ageLimit);

            KidsRoom(const KidsRoom& room);

            EscapeRoomWrapper* clone()const override ;

            /*!
             * function sets the age limit field to new (given) param.
             * @param limit - the new age limit.
             *
             * @throw KidsRoomIllegalAgeLimit - if limit < MIN.
             */
            void setNewAgeLimit(const int& limit);

            /*!
             * function returns the age limit param. for the applied room.
             * @return int age limit.
             */
            int getAgeLimit() const;

        };
        /*!
         * function defines a new printing method for kids room.
         * will print as:
         * Kids Room: <name> (<maxTime>/<level>/<maxParticipants>/<ageLimit>)
         * @param output - the given output channel.
         * @param room - the room to print.
         */
        std::ostream& operator<<(std::ostream& output, const KidsRoom& room);
    }
}

#endif //EX4_WET_KIDSROOM_H
