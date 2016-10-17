#include "Enigma.hpp"
#include <iostream>

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
    cout << "Plug" << n << endl;
    for(vector<Rotor>::iterator it = rotors.begin(); it != rotors.end(); it++) {
        n = it -> get(n);
        cout << "Rotor" << n << endl;
    }
    n = reflector.get(n);
    for (vector<Rotor>::reverse_iterator it = rotors.rbegin(); 
            it != rotors.rend(); it++ ) { 
        n = it -> getInverse(n);
        cout << "Rotor" << n << endl;
    } 
    n = plugboard.get(n);
    cout << "Plug" << n << endl;
    count++;
    rotate();
    return n;
}

void Enigma::rotate()
{
    
}
