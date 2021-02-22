#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    // need to provide hash(T e), e1 == e2
    unordered_set<int> s = {5, 1, 2, 3, 5, 5, 6, 8, 0};

    for (auto e : s)
    {
        cout << " " << e;
    }
    cout << endl;

    cout << (s.find(4) != s.end() ? "Yes" : "No") << endl;

    //need to provide T e1, e2; e1 < e2
    set<int> s2 = {5, 1, 2, 3, 5, 5, 6, 8, 0};

    for (auto e : s2)
    {
        cout << " " << e;
    }
    cout << endl;

    cout << (s2.find(4) != s2.end() ? "Yes" : "No") << endl;
}