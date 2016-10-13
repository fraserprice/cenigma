#include "Rotor.hpp"
#include <stdexcept>
#include <fstream>

using namespace std;

vector<int> parseFile(char* filename)
{
    ifstream infile(filename);
    int n;
    vector<int> nums;
    while(infile >> n)
    {
        nums.push_back(n);
    }
    return nums;
}

int main(int argc, char **argv)
{
    int length = sizeof(argv)/sizeof(argv[0]);
    vector<int> rotors[length];
    for(int i = 1; i < length + 1; i++)
    {
        rotors[i - 1] = parseFile(argv[i]);
    }
    for(int i = 0; i < length; i++)
    {
        Rotor r (rotors[i]);
    }
    return 0;
}
