#include <iostream>
#include <map>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    map<int, int> snows;

    for (int i = 0; i < cases; i++)
    {
        int numSnow;
        cin >> numSnow;
        int start = 1;
        int sol = 0;

        for (int i = 1; i <= numSnow; i++)
        {
            int n;
            cin >> n;
            if (snows[n] >= start)
            {
                if (i - start > sol)
                {
                    sol = i - start;
                    start = snows[n] + 1;
                }
            }
            snows[n] = i;
        }
        if (numSnow + 1 - start > sol)
        {
            sol = numSnow + 1 - start;
        }
        cout << sol << endl;
    }
}