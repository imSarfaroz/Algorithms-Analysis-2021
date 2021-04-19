#include <iostream>

using namespace std;

int main()
{
    int num;
    char game[100][100];

    while (cin >> num)
    {
        if (num == 0)
            break;

        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cin >> game[i][j];
            }
        }
    }
}