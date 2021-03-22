// C++ Java Java
// C Python
// C# Python
// C++ C++

// C: 2
// C++: 1 2
// Java: 1
// Python: 2 3
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    map<string, set<int>> d;

    int nLine = 0;
    for (string line; getline(cin, line);)
    {
        ++nLine;
        istringstream sinp(line);
        for (string w; sinp >> w;)
        {
            d[w].insert(nLine);
        }
    }

    for (const auto &p : d)
    {
        cout << p.first << ":";
        for (const auto &e : p.second)
        {
            cout << " " << e;
        }
        cout << endl;
    }
}