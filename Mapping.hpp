#ifndef MAPPING_H
#define MAPPING_H

#include <map>
#include <vector>

using namespace std;

class Mapping
{
    public:

        int get(int);
        int getInverse(int);

    protected:

        map<int, int> mapping;

};

#endif
