#ifndef ROTOR_H
#define ROTOR_H

#include "Mapping.hpp"

using namespace std;

class Rotor : public Mapping
{
    public:

        Rotor(vector<int>);
        int getInverse(int);

    private:

        map<int, int> inverseMapping;
    
};

#endif
