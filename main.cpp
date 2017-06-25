#include <iostream>
#include "Enigma.h"
#include "EscapeRoomWrapper.h"


using mtm::escaperoom::EscapeRoomWrapper;
using mtm::escaperoom::Enigma;
int main(){
    char* name="sd";
    EscapeRoomWrapper roomWrapper(name,50,4,2);
    Enigma enigma("riddle", mtm::escaperoom::EASY_ENIGMA);
    roomWrapper.addEnigma(enigma);
    roomWrapper.removeEnigma(enigma);
    return 0;
}