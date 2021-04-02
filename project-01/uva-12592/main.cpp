#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, string> slogans;

    string first;
    getline(cin, first);

    for (int i = 1; i <= n; ++i)
    {
        getline(cin, first);

        getline(cin, slogans[first]);
    }

    int test;
    cin >> test;
    getline(cin, first);

    for (int i = 0; i < test; ++i)
    {
        getline(cin, first);

        cout << slogans[first] << endl;
    }
}