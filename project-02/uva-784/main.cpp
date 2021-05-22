#include <iostream>
#include <stdio.h>
#include <map>

char map[100][100];

void dfs(int i, int j);

int main()
{
    int num;

    std::cin >> num;
    while (num--)
    {
        int n = 0;
        while (gets(map[n]))
        {
            if (map[n][0] == '_')
            {
                break;
            }
            n++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == '*')
                {
                    dfs(i, j);
                }
            }
        }

        for (int i = 0; i <= n; i++)
            puts(map[i]);
    }
}

void dfs(int i, int j)
{
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}