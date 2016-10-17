#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Enigma.hpp"
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
    vector<Rotor> rotors;
    for(int i = 1; i < argc - 1; i++)
    {
        rotors.push_back(Rotor(parseFile(argv[i])));
    }
    Plugboard plugboard (parseFile(argv[argc - 1]));
    Enigma enigma (rotors, plugboard);
    enigma.encode(1);
    return 0;
}
