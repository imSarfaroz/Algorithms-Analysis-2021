#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int> &v)
{
    for(auto e : v)
    {
        cout << " " << e;
    }

    cout << endl;
}

void printInReversedOrder(const list <int> &v)
{
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << " " << *i;
    }

    cout << endl;
}

int main()
{
    list<int> v;

    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    printInDirectOrder(v);
    printInReversedOrder(v);

    for (auto i = v.begin(); i != v.end(); i++)
    {
        if(*i % 2 == 0)
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
}
