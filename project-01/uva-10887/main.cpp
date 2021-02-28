#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int numOfCases;
    cin >> numOfCases;

    for (int i = 0; i < numOfCases; i++)
    {
        int a;
        int b;
        cin >> a;
        cin >> b;
        unordered_set<string> lanA(a);
        unordered_set<string> lanB(b);
        }
}