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

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            s[0] = 'a' + i, s[1] = 'a' + j;
            letters[s] = num++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            for (int k = j + 1; k < 26; k++)
            {
                s[0] = 'a' + i, s[1] = 'a' + j, s[2] = 'a' + k;
                letters[s] = num++;
            }
        }
    }

    while (cin >> s)
    {
        cout << letters[s] << endl;
    }
}