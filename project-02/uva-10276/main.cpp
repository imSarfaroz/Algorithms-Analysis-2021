#include <iostream>

using namespace std;

int num, total;
int p;
int con[100];

void isSquare(int cur, int pos);

int main()
{
    cin >> num;

    while (num--)
    {
        cin >> p;

        isSquare(1, 0);
    }
}

void isSquare(int cur, int pos)
{
    if (pos == num)
        return;

    if (con[pos] == 0)
    {
        total++;
    }
}