#include "Enigma.h"


namespace mtm {
    namespace escaperoom {

        /*Enigma::Enigma(const std::string &name, const Difficulty &difficulty,
                       const int &numOfElements) :
                name(std::string(name)),
                difficulty(difficulty),
                numOfElements(numOfElements) {
        }*/

        Enigma::Enigma(const std::string& name, const Difficulty& difficulty,
               const int& numOfElements, const set<string>& elements):
                name(std::string(name)),
                difficulty(difficulty),
                numOfElements(numOfElements),
                elements(elements){
            int temp_size = (int)elements.size();
            if (numOfElements != temp_size){
                throw EnigmaIllegalSizeParamException();
            }
        }

        Enigma::Enigma(const std::string& name, const Difficulty& difficulty):
                name(std::string(name)),
                elements(),
                difficulty(difficulty){
            numOfElements = 0;
        }

        void Enigma::addElement(const string& element){
            elements.insert(element);
            numOfElements = (int)elements.size();
        }

        void Enigma::removeElement(const string& element){
            set<string>::iterator iterator = elements.find(element);
            if (iterator == elements.end()){
                throw EnigmaElementNotFundException();
            }
            elements.erase(element);
        }

        bool Enigma::operator==(const Enigma& enigma) const{
            return difficulty == enigma.difficulty && name == enigma.name;
        }

        bool Enigma::operator!=(const Enigma& enigma) const{
            return !(*this == enigma);
        }

        bool Enigma::operator<(const Enigma& enigma) const{
            return difficulty < enigma.difficulty;
        }

        bool Enigma::operator>(const Enigma& enigma) const{
            return enigma < *this;
        }

        bool Enigma::areEqualyComplex(const Enigma& enigma) const{
            return enigma.difficulty == difficulty &&
                    enigma.numOfElements == numOfElements;
        }

        Difficulty Enigma::getDifficulty() const{
            return difficulty;
        }

        string Enigma::getName() const{
            return name;
        }
        //<name> (<Difficulty>) <number of items>
        std::ostream& operator<<(std::ostream& output, const Enigma& enigma){
            string difficulty_string;
            switch(enigma.difficulty){
                case EASY_ENIGMA:
                    difficulty_string = "EASY_ENIGMA";
                    break;
                case MEDIUM_ENIGMA:
                    difficulty_string = "MEDIUM_ENIGMA";
                    break;
                case HARD_ENIGMA:
                    difficulty_string = "HARD_ENIGMA";
                    break;
            }
            return output << enigma.name << " (" << difficulty_string << ") "
                          << enigma.numOfElements;
        }
    }
}