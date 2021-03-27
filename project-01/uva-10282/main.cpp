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
        sinp >> eng;

        string foreign;
        sinp >> foreign;

        if (eng.empty())
            break;

        dict[foreign] = eng;
    }

    string input;
    while (cin >> input)
    {
        if (!dict[input].empty())
        {
            cout << dict[input] << endl;
        }
        else
        {
            cout << "eh\n";
        }
    }
}