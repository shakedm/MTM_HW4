#include "Enigma.h"


namespace mtm {
    namespace escaperoom {

        Enigma::Enigma(const std::string &name, const Difficulty &difficulty,
                       const int &numOfElements) :
                name(std::string(name)),
                difficulty(difficulty),
                numOfElements(numOfElements) {
        };

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
        friend std::ostream& Enigma::operator<<(std::ostream& output,
                                        const Enigma& enigma){
            return output << enigma.name << " (" << enigma.difficulty << ") "
                          << enigma.numOfElements;
        }
    }
}