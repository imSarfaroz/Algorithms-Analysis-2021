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

    // test cases
}