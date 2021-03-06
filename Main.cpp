#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Enigma.hpp"
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

vector<int> parseFile(char* filename)
{
    ifstream infile(filename);
    if(infile.fail())
    {
        throw invalid_argument("Filed to open file; please check paths are correct");
    }
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
    if(argc == 1)
    {
        throw invalid_argument("You must input a pulgboard!");
    }
    vector<Rotor> rotors;
    for(int i = 1; i < argc - 1; i++)
    {
        rotors.push_back(Rotor(parseFile(argv[i])));
    }
    Plugboard plugboard (parseFile(argv[argc - 1]));
    Enigma enigma (rotors, plugboard);
    string input;
    while (getline(cin, input))
    {
        vector<int> toEncode;
        for(string::size_type i = 0; i < input.size(); ++i) {
            if(isupper(input[i]))
            {
                cout << (char) (enigma.encode(input[i] - 65) + 65);
            } else if(!iswspace(input[i]))
            {
                throw invalid_argument("Input must either be upper case letter or whitespace");
            }
        }
    }
    return 0;
}
