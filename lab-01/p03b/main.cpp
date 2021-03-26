#include <iostream>
#include <list>
#include "List.hpp"

using namespace std;

void printInDirectOrder(List<int> &v)
{

    for (auto p = v.begin(); p != v.end(); ++p)
    {
        cout << " " << *p;
    }
    cout << endl;
}

void printInReversedOrder(List<int> &v)
{
    for (auto p = v.rbegin(); p != v.rend(); p++)
    {
        cout << " " << *p;
    }

    cout << endl;
}

int main()
{
    List<int> v;

    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printInDirectOrder(v);
    printInReversedOrder(v);

    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (*i % 2 == 0)
        {
            v.insert(i, 0);
        }
    }

    printInDirectOrder(v);
    printInReversedOrder(v);

    for (auto i = v.begin(); i != v.end();)
    {
        if (*i % 2 == 0)
        {
            i = v.erase(i);
        }
        else
        {
            ++i;
        }
    }

    printInDirectOrder(v);
    printInReversedOrder(v);

    cout << v.size() << endl;
}
