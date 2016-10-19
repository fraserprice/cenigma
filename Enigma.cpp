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
    cout << "Start: " << n << endl;
    n = plugboard.get(n);
    cout << "Plugboard: " << n << endl;
    if(rotors.size() > 0)
    {
        for(vector<Rotor>::iterator it = rotors.begin(); it != rotors.end(); it++) {
            n = it -> get(n);
            cout << "Get: " << n << endl;
        }
    }
    n = reflector.get(n);
    cout << "Reflect: " << n << endl;
    if(rotors.size() > 0)
    {
        for (vector<Rotor>::reverse_iterator it = rotors.rbegin(); 
            it != rotors.rend(); it++ ) { 
            n = it -> getInverse(n);
            cout << "Inverse: " << n << endl;
        } 
    }
    n = plugboard.get(n);
    cout << "Plugboard: " << n << endl;
    if(rotors.size() > 0)
    {
        rotate();
    }
    count++;
    return n;
}

void Enigma::rotate()
{
    int rotor = (count / 26) % rotors.size();
    rotors.at(rotor).rotate();
}
