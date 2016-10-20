#include "Enigma.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Enigma::Enigma(const vector<Rotor> &rotors, const Plugboard &plugboard)
    : plugboard(plugboard)
    , reflector(Reflector())
    , rotors(rotors)
    , count(0)
{
}

int Enigma::encode(int n)
{
    n = plugboard.get(n);
    if(rotors.size() > 0)
    {
        for(vector<Rotor>::iterator it = rotors.begin(); it != rotors.end(); it++) {
            n = it -> get(n);
        }
    }
    n = reflector.get(n);
    if(rotors.size() > 0)
    {
        for (vector<Rotor>::reverse_iterator it = rotors.rbegin(); 
            it != rotors.rend(); it++ ) { 
            n = it -> getInverse(n);
        } 
    }
    n = plugboard.get(n);
    if(rotors.size() > 0)
    {
        count++;
        rotate();
    }
    return n;
}

void Enigma::rotate()
{
    int rotor = 0;
    for(double i = rotors.size() - 1; i >= 0; i--)
    {
        if(count % (int) (pow(26.0, i) + 0.5) == 0)
        {
            rotors.at(i).rotate();
        }
    }
}
