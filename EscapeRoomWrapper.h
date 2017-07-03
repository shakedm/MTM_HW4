#ifndef ESCAPEROOMWRAPPER_H
#define ESCAPEROOMWRAPPER_H

#include <string>
#include <iostream>
#include "EscapeRoom.h"

#include "Enigma.h"
#include <vector>


namespace mtm{
namespace escaperoom {
using std::string;
using std::vector;
    class EscapeRoomWrapper {
        EscapeRoom escaperoom;
        vector<Enigma> roomEnigma;
    public:
        // Constructs a new Escape Room with the specified data.
        //
        // @param name : the name of the escape room.
        // @param escapeTime : the maximal escape time allowed in the room.
        // @param level : the level of the escape room.
        // @param maxParticipants: the maximal participants allowed in the room.
        // The rest of the room's data is initialized as described in the exercise sheet.
        // @throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(char* name, const int& escapeTime, const int& level, const int& maxParticipants);

        // Constructs a new Escape Room with the specified data.
        //
        // @param name : the name of the enigma.
        // @param level : the level of the escape room.
        // The rest of the room's data is initialized as described in the exercise sheet.
        // @throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(char* name, const int& level);

        virtual EscapeRoomWrapper* clone() const;

        //copy constructor
        //
        //@param room : the room to be copied.
        //@throws EscapeRoomMemoryProblemException in case of creation failure.
        EscapeRoomWrapper(const EscapeRoomWrapper& room);

        //assignment operator
        //
        //@param room : the room to be assigned.
        EscapeRoomWrapper& operator=(const EscapeRoomWrapper& room);

        // Comparison operators for Escape Rooms. rooms are compared as described in
        // the exercise sheet.
        //
        // @param room : the right-hand side operand.
        bool operator==(const EscapeRoomWrapper& room) const;
        bool operator!=(const EscapeRoomWrapper& room) const;
        bool operator<(const EscapeRoomWrapper& room) const;
        bool operator>(const EscapeRoomWrapper& room) const;

        bool operator<=(const EscapeRoomWrapper& room) const = delete;
        bool operator>=(const EscapeRoomWrapper& room) const = delete;

        // return the level of the Escape Room.
        //
        int level() const;

        // the method changes the rate according to the rate given.
        //
        // @param newRate : the new rate accepted to the room.
        //@throws EscapeRoomIllegalRateException in case of illegal rate parameter.
        void rate(const int& newRate) const;

        // Destructor for EscapeRoomWrapper
        virtual ~EscapeRoomWrapper();

        // Prints the data of the Room in the following format:
        //
        //     "<name> (<maxTime>/<level>/<maxParticipants>)"
        //
        // @param output : the output stream to which the data is printed.
        // @param room : the room whose data is printed.
        friend std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);

        //Function returns the name of the EscapeRoom.
        //
        std::string getName() const;

        //Function returns the rate of the EscapeRoom.
        //
        double getRate() const;

        //Function returns the maximum escape time of the EscapeRoom.
        //
        int getMaxTime() const;

        //Function returns the number of participants allowed in the EscapeRoom.
        //
        int getMaxParticipants() const;
        /*!
         * function recieves an enigma and adds it to the room's enigma vector
         * @param enigma - the enigma to add.
         */
        void addEnigma(const Enigma& enigma);

        /*!
         * function removes the given enigma from the room's enigma vector.
         * @param enigma - the enigma to remove.
         *
         * @throw - EscapeRoomNoEnigmasException - in case there are no enigmas
         *                                          in the room.
         *       - .EscapeRoomEnigmaNotFoundException - in case the given enigma
         *                                          isn't found in the room's
         *                                          enigmas vector.
         */
        void removeEnigma(const Enigma& enigma);

        /*!
         * function returns the enigma with the highest difficulty level (if
         * there is more than one, function returns the first that's found)
         * @return - the hardest of the room's enigmas
         *
         * @throw - .EscapeRoomNoEnigmasException - in case there are no
         * enigmas in the room.
         */
        Enigma getHardestEnigma();

        /*!
         * function returns the room's enigmas vector.
         * @return - vector with enigma type nodes
         */
        vector<Enigma>& getAllEnigmas();

    };

    /*!
     * print operator overloading. prints in the following format:
     * <name> (<maxTime>/<level>/<maxParticipants>)
     * @param output - the output channel to ptint to.
     * @param room - the room to print the info about.
     *
     * @return print.
     */
    std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room);
} // end of namespace eascaperoom
} // end of namespace mtm


#endif //ESCAPEROOMWRAPPER_H
