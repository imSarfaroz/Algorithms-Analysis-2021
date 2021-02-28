#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int numOfCases;
    cin >> numOfCases;
    int count = 1;

    for (int i = 0; i < numOfCases; i++)
    {
        int a;
        int b;
        cin >> a;
        cin >> b;
        vector<string> lanA(a);
        vector<string> lanB(b);
        getchar();

        unordered_set<string> languages;

        for (int i = 0; i < a; i++)
        {
            getline(cin, lanA[i]);
        }

        for (int i = 0; i < b; i++)
        {
            getline(cin, lanB[i]);
        }

        cout << "Case " << count++ << ": ";

        for (int j = 0; j < b; ++j)
        {
            for (int k = 0; k < a; ++k)
            {
                languages.insert(lanA[k] + lanB[j]);
            }
        }

        cout << languages.size() << endl;
    }
}