#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numTest;
    cin >> numTest;

    for (int t = 0; t < numTest; t++)
    {
        set<int> chocolates[3];
        int p[3];
        set<int> every_choco;

        for (int i = 0; i < 3; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < p[i]; j++)
            {
                int num;
                cin >> num;
                chocolates[i].insert(num);
                every_choco.insert(num);
            }
        }

        int counter[3][2] = {0};

        for (int i = 0; i < 3; i++)
        {
            for (auto j : chocolates[i])
            {
                auto p1 = chocolates[(i + 1) % 3].find(j);
                auto p2 = chocolates[(i + 2) % 3].find(j);

                if (p1 == chocolates[(i + 1) % 3].end() && p2 == chocolates[(i + 2) % 3].end())
                {
                    counter[i][0]++;
                }
            }

            for (auto j : every_choco)
            {
                if (chocolates[i].find(j) == chocolates[i].end() &&
                    chocolates[(i + 1) % 3].find(j) != chocolates[(i + 1) % 3].end() && chocolates[(i + 2) % 3].find(j) != chocolates[(i + 2) % 3].end())
                {
                    counter[i][1]++;
                }
            }
        }

        cout << "Case #" << t + 1 << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << counter[i][0] << " " << counter[i][1] << endl;
        }
    }
}