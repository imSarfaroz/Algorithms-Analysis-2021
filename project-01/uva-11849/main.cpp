#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{

    while (true)
    {
        unordered_set<int> cd;

        int jack;
        int jill;

        cin >> jack;
        cin >> jill;

        if (jack == 0 && jill == 0)
        {
            break;
        }

        // inserting
        for (int i = 0; i < jack; i++)
        {
            int n;
            cin >> n;
            cd.insert(n);
        }

        // calculations

        cout << //calculations
    }
}