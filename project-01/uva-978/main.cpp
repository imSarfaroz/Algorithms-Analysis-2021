#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    for (int i = 0; i < numOfCase; i++)
    {
        multiset<int, int> gl;
        multiset<int, int> bl;

        int bf;
        cin >> bf;
        int g;
        cin >> g;
        int b;
        cin >> b;

        for (int j = 0; i < g; j++)
        {
            int temp;
            cin >> temp;
            gl.insert(temp);
        }

        for (int j = 0; j < b; j++)
        {
            int temp;
            cin >> temp;
            bl.insert(temp);
        }
    }

    return 0;
}