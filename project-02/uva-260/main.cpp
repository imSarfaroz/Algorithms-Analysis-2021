#include <iostream>

using namespace std;

int num;
char game[100][100];
bool been[100][100];

bool dfs(int a, int b, char c);

int main()
{
    int count = 0;
    

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

        // cheking if b winner
        for (int i = 0; i < num; i++)
        {
            if (game[0][i] == 'b')
            {
                for (int a = 0; a < num; a++)
                {
                    for (int b = 0; b < num; b++)
                    {
                        been[a][b] = false;
                    }
                }
                been[0][i] = true;
                hasWon = dfs(0, i, 'b');
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

bool dfs(int a, int b, char c)
{
    if(a == num - 1)
    {
        return true;
    }

    if (a > 0 && b > 0 && game[a - 1][b - 1] == c && !been[a - 1][b - 1])
    {
        been[a - 1][b - 1] = true;
        if (dfs(a - 1, b - 1, c))
            return true;
    }

    if (a > 0 && !been[a - 1][b] && game[a - 1][b] == c)
    {
        been[a - 1][b] = true;
        if (dfs(a - 1, b, c))
            return true;
    }

    if (b > 0 && !been[a][b - 1] && game[a][b - 1] == c)
    {
        been[a][b - 1] = true;
        if (dfs(a, b - 1, c))
            return true;
    }

    if (b < num - 1 && !been[a][b + 1] && game[a][b + 1] == c)
    {
        been[a][b + 1] = true;
        if (dfs(a, b + 1, c))
            return true;
    }

    if (a < num - 1 && !been[a + 1][b] && game[a + 1][b] == c)
    {
        been[a + 1][b] = true;
        if (dfs(a + 1, b, c))
            return true;
    }

    if (a < num - 1 && b < num - 1 && !been[a + 1][b + 1] && game[a + 1][b + 1] == c)
    {
        been[a + 1][b + 1] = true;
        if (dfs(a + 1, b + 1, c))
            return true;
    }

        return false;
}