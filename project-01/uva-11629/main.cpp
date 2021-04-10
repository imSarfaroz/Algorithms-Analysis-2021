#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int party;
    int guess;
    cin >> party;
    cin >> guess;

    unordered_map<string, int> ballot;

    for (int i = 0; i < party; i++)
    {
        string a;
        cin >> a;
        float b;
        cin >> b;

        ballot[a] = b;
    }

    for (int j = 1; j <= guess; j++)
    {
        string s;
        cin >> s;
        int count = 0;

        while(true)
        {
            if(s != "+")
            {
                count += ballot[s];
            }
            cin >> s;
        }
        int n;
        cin >> n;

        cout << "Case #" << j;
        if(s == ">")
        {
            cout << (count > n ? "was correct." : "was incorrect");
        }
    }
}