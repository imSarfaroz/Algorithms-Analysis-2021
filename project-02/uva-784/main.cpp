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
    }
}

void dfs(int i, int j);
{
}