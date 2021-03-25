#include <iostream>
#include <string>

#include "MapStrInt.hpp"

using namespace std;

int main()
{
    MapStrInt m;

    string w;
    while (cin >> w)
    {
        ++m[w];
    }

    m.printInOrder();
    cout << "size: " << m.size() << endl;
}