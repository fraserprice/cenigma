#include "Rotor.hpp"
#include <iostream>

using namespace std;

Rotor::Rotor(vector<int> vectorMapping)
{
    setMapping(vectorMapping);
}

int Rotor::getInverse(int in)
{
   return inverseMapping[in]; 
}

void Rotor::setMapping(vector<int> vectorMapping)
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

void Rotor::rotate()
{
    vector<int> vectorMapping;
    for(int i = 0; i < 26; i++)
    {
        vectorMapping.push_back((mapping[(i + 1) % 26] + 25) % 26);
    }
    setMapping(vectorMapping);
}
