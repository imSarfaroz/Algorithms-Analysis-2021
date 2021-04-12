#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int c, int sum, const vector<int> v)
{
    if (c == v.size())
    {
        cout << "sum: " << sum << "\n";
    }
    else
    {
        solve(c + 1, sum, v);
        solve(c + 1, sum + v[c], v);
    }
}

int main()
{
    for (int d, n; cin >> d >> n;)
    {
        vector<int> v(n);
        for (auto &e : v)
        {
            cin >> e;
        }

        solve(0, 0, v);
    }
}