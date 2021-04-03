#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    set<int> num;
    int numbers[1000];
    set<int>::iterator it;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        for (int i = 0; i < a; i++)
        {
            cin >> numbers[i];
        }

        num.insert(numbers[0]);
        bool isFirst = true;
        int sz = 1;

        for (int i = 0; i < b; i++)
        {
            int c;
            cin >> c;

            while (c > sz)
            {
                num.insert(numbers[sz]);
                if (*it > numbers[sz])
                {
                    it--;
                }
                sz++;
            }
        }
    }
}
}