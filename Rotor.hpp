#ifndef ROTOR_H
#define ROTOR_H

#include "Mapping.hpp"
#include <iostream>

class Rotor : public Mapping
{
    public:

        Rotor(vector<int>);
    
    private:
        
        void setMapping(vector<int>);
};

#endif
