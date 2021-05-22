#include <iostream>
#include <stdio.h>
#include <map>

char map[100][100];

int main()
{
    int num;
    int x, y;

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
    }
}