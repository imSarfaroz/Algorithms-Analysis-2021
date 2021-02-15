#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    unordered_set<string> setOfWords;

    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);

        string cmd;
        sinp >> cmd;

        if (cmd == "+")
        {
            string word;
            sinp >> word;
            auto p = setOfWords.insert(word);
            cout << (p.second ? "YES" : "NO") << endl;
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            auto it = setOfWords.find(word);
            cout << (it != setOfWords.end() ? "YES" : "NO") << endl;
        }
    }
}