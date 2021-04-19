#include <iostream>

using namespace std;

int main()
{
    int num;
    int count = 0;
    char game[100][100];
    bool been[100][100];

    while (cin >> num)
    {
        if (num == 0)
            break;

        count++;

        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cin >> game[i][j];
            }
        }

        bool hasWon = false;

        // cheking winner
        for (int i = 0; i < num; i++)
        {
            if (game[0][i] == 'b')
            {
                for (int a = 0; a < num; i++)
                {
                    for (int b = 0; b < num; b++)
                    {
                        been[a][b] = false;
                    }
                }
                been[0][i] = true;
                hasWon = dfs();
                if (hasWon)
                    break;
            }
        }

        if (hasWon)
        {
            cout << count << " "
                 << "B" << endl;
        }
        else
        {
            cout << count << " "
                 << "W" << endl;
        }
    }
}