#include "KidsRoom.h"


namespace mtm{
    namespace escaperoom {

        KidsRoom::KidsRoom(char* name, const int& escapeTime, const int& level,
                 const int& maxParticipants, const int& ageLimit):
                EscapeRoomWrapper(name, escapeTime, level, maxParticipants) {
            if (ageLimit < MIN){
                throw KidsRoomIllegalAgeLimit();
            }
            AgeLimit = ageLimit;
        }

        void KidsRoom::setNewAgeLimit(const int& limit){
            if (limit < MIN){
                throw KidsRoomIllegalAgeLimit();
            }
            AgeLimit = limit;
        }

        int KidsRoom::getAgeLimit() const{
            return this->AgeLimit;
        }

        std::ostream& operator<<(std::ostream& output,
                                           const KidsRoom& room){
            return output << "Kids Room: " << room.getName() << " (" <<
                   room.getMaxTime() << "/" << room.level() << "/" <<
                   room.getMaxParticipants() << "/"<< room.getAgeLimit() << ")";
        }

    }
}