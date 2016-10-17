#include "Plugboard.hpp"
#include <iostream>

using namespace std;

Plugboard::Plugboard(vector<int> vectorMapping)
{
    for(int i = 0; i < 26; i++)
    {
        mapping[i] = i;
    }
    for(int i = 0; i < vectorMapping.size(); i+=2)
    {
        mapping[vectorMapping[i]] = vectorMapping[i+1];
        mapping[vectorMapping[i+1]] = vectorMapping[i];
    }
}
