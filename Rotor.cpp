#include "Rotor.hpp"

using namespace std;

Rotor::Rotor(vector<int> vectorMapping)
{
    setMapping(vectorMapping); 
}

void Rotor::setMapping(vector<int> vectorMapping)
{
    for(int i = 0; i < 26; i++)
    {
        mapping[i] = vectorMapping.at(i);
        cout << "Mapping " << i << " to " << mapping[i] << endl;
    }
    for (map<int, int>::iterator i = mapping.begin(); i != mapping.end(); ++i)
    {
        inverseMapping[i->second] = i->first;
    }
}   
