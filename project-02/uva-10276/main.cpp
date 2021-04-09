#include <iostream>
#include <cmath>

using namespace std;

int num, total;
int p;
int con[100];

void isSquare(int cur, int pos)
{
    if (pos == p)
        return;

    if (con[pos] == 0)
    {
        total++;
        con[pos] = cur;
        return isSquare(cur + 1, pos);
    }

    for (int i = 0; i <= pos; i++)
    {
        int r = sqrt(con[i] + cur);
        if ((r * r) == con[i] + cur)
        {
            total++;
            con[i] = cur;
            return isSquare(cur + 1, pos);
        }
    }

    isSquare(cur, pos + 1);
}

int main()
{
    cin >> num;
    
    while (num--)
    {
        total = 0;
        cin >> p;

        isSquare(1, 0);
        cout << total << endl;
    }
}
