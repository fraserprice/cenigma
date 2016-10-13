#ifndef MAPPING_H
#define MAPPING_H

#include <map>
#include <vector>

using namespace std;

class Mapping
{
    protected:

        map<int, int> mapping;
        map<int, int> inverseMapping;

        int get(int, bool);

};

#endif
