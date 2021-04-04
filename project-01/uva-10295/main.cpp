#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> sal;

    int w, d;
    string word;
    int usd;

    cin >> w >> d;
    long total = 0;

    for (int i = 0; i < w; i++)
    {
        cin >> word >> usd;
        sal[word] = usd;
    }

    for (int j = 0; j < d; j++)
    {
        total = 0;
        while (cin >> word && word != ".")
            total = total + sal[word];
        cout << total << endl;
    }
}