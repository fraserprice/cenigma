#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(vector<int> vectorMapping)
{
    for(int i = 0; i < 26; i++)
    {
        mapping[i] = vectorMapping.at(i);
    }
    for (map<int, int>::iterator i = mapping.begin(); i != mapping.end(); ++i)
    {
        inverseMapping[i->second] = i->first;
    }
}

int Rotor::getInverse(int in)
{
   return inverseMapping[in]; 
}
