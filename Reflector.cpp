#include "Reflector.hpp"

using namespace std;

Reflector::Reflector()
{
    for(int i = 0; i < 26; i++)
    {
        mapping[i] = (i + 13) % 26;
    }
}
