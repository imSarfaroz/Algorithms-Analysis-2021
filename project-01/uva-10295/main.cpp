#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> sal;

    int w, d;
    cin >> w >> d;

    for (int i = 0; i < w; i++)
    {
        string word;
        int usd;

        cin >> word >> usd;
        sal[word] = usd;
    }
}