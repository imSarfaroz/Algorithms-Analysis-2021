#include <iostream>
//#include <vector>

using namespace std;

void readAndPrintInReversedOrder()
{
    int x;
    if (cin >> x)
    {
        readAndPrintInReversedOrder(); // recursion
        cout << " " << x;
    }
}

int main()
{
    readAndPrintInReversedOrder();
    cout << endl;
}

// vector<int> v;

// for (int x; cin >> x;)
// {
//     v.push_back(x);
// }

// for (auto i = v.rbegin(); i != v.rend(); i++)
// {
//     cout << " " << *i;
// }
// cout << endl;