#include "Enigma.h"

#define NONE 0


namespace mtm {
    namespace escaperoom {

        /*Enigma::Enigma(const std::string &name, const Difficulty &difficulty,
                       const int &numOfElements) :
                name(std::string(name)),
                difficulty(difficulty),
                numOfElements(numOfElements) {
        }*/

        Enigma::Enigma(const string& name, const Difficulty& difficulty,
               const int& numOfElements, const set<string>& elements):
                difficulty(difficulty),
                numOfElements(numOfElements),
                name(name),
                elements(elements){
            int temp_size = (int)elements.size();
            if (numOfElements != temp_size){
                throw EnigmaIllegalSizeParamException();
            }
        }

        Enigma::Enigma(const string& name, const Difficulty& difficulty):
                difficulty(difficulty),
                name(name),
                elements(){
            numOfElements = NONE;
        }

        void Enigma::addElement(const string& element){
            elements.insert(element);
            numOfElements = (int)elements.size();
        }

        void Enigma::removeElement(const string& element){
            if(numOfElements == NONE){
                throw EnigmaNoElementsException();
            }
            set<string>::iterator iterator = elements.find(element);
            if (iterator == elements.end()){
                throw EnigmaElementNotFoundException();
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
            return output << enigma.name << " (" << enigma.difficulty << ") "
                          << enigma.numOfElements;
        }
    }
}