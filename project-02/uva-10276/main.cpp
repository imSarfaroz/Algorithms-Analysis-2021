#include <iostream>
#include <cmath>

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
        cout << total;
    }
}

void isSquare(int cur, int pos)
{
    if (pos == num)
        return;

    if (con[pos] == 0)
    {
        total++;
        return isSquare(cur + 1, pos);
    }

    for (int i = 0; i <= pos; i++)
    {
        int r = sqrt(con[i] + cur);
        if ((r * r) == con[i] + cur)
        {
            total++;
            return isSquare(cur + 1, pos);
        }
    }
    isSquare(cur, pos + 1);
}