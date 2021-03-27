#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    unordered_map<string, string> dict;
    string line;

    while (getline(cin, line))
    {
        istringstream sinp(line);
        string eng;
        cin >> eng;

        string foreign;
        cin >> foreign;

        dict[foreign] = eng;
    }

    string input;
    while (cin >> input)
    {
        // find a word if else
        // print
    }
}