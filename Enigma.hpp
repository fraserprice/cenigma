#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"

using namespace std;

class Enigma
{
    public:

        Enigma(const vector<Rotor> &rotors, const Plugboard &plugboard);
        int encode(int);

    private:

        vector<Rotor> rotors;
        Plugboard plugboard;
        Reflector reflector;
        int count;
        void rotate();
    
};

#endif
