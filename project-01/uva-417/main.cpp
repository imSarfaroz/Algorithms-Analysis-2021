#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> letters;
    int num = 1;
    string s;

    for (int i = 0; i < 26; i++)
    {
        s = 'a' + i;
        letters[s] = num++;
    }

    while (cin >> s)
    {
        cout << letters[s] << endl;
    }
}