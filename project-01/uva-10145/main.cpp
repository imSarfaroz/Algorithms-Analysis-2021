#include <iostream>
#include <unordered_map>
#include <sstream>

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

            // DENIED  GRANTED  logic
        }
    }
}