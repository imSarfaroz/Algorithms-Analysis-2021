#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> letters;
    int num = 0;
    string s;

    for (int i = 0; i < 26; i++)
    {
        s = 'a' + i;
        letters[s] = num++;
    }

    cout << letters[s] << endl;
}