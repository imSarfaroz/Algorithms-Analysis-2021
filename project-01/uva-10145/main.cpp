#include <iostream>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    int numOfTest;
    cin >> numOfTest;

    string line;
    getline(cin, line);

    for (int i = 0; i < numOfTest; i++)
    {
        getline(cin, line);

        unordered_map<int, bool> ignored;
        unordered_map<int, bool> occured;

        unordered_map<int, char> mode;
        unordered_map<int, set<int>> owner;

        while (getline(cin, line) && line != "#")
        {
            char a;
            int id, owned;

            stringstream s;
            s << line;
            s >> a >> id >> owned;

            if (ignored[id])
            {
                cout << "IGNORED" << endl;
            }
            else if (occured[owned] && (mode[owned] == 'X' || a == 'X'))
            {
                cout << "DENIED" << endl;
                ignored[id] = true;
            }
            else
            {
                cout << "GRANTED" << endl;
                if (a == 'X')
                {
                    mode[owned] = 'X';
                }
                else
                {
                    mode[owned] = 'S';
                }

                owner[owned].insert(id);
                occured[owned] = true;
            }
        }
    }
}