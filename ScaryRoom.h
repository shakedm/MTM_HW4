

#ifndef EX4_WET_SCARYROOM_H
#define EX4_WET_SCARYROOM_H

#include "EscapeRoomWrapper.h"




namespace mtm{
    namespace escaperoom{
class ScaryRoom : public EscapeRoomWrapper {
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

    /*!
     * the default destructor calls the destructor of father class,
     * which is good for us
     */
    ~ScaryRoom()= default;

    /*!
     * the default operator is not good for us, therefore i need to work more
     * @param room the room to copy
     * @return a reference to the copied room
     */
    ScaryRoom&operator=(const ScaryRoom room);


    /*!
     * function sets a new age limit in the private field of scary room
     * @param ageLimit a const int only used to set the field
     */
    void setNewAgeLimit(const int& ageLimit);


    /*!
     * function increase the private field of scary enigmas by 1
     */
    void incNumberOfScaryEnigmas();


    /*!
     * function gets the age limit does not change Scary room
     * @return an integer from the private field
     */
    int getAgeLimit() const ;

    /*!
     * function prints the fields by the template provided
     * @param output the channel to print to
     * @return to the output channel
     */

    };
    std::ostream& operator<<(std::ostream& output,const ScaryRoom& room);
}
}
#endif //EX4_WET_SCARYROOM_H
