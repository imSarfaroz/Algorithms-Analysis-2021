#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve(int c, int sumOfCD, const int v, const vector<int> &num, vector<int> &result, bool &hasChecked)
{
    if (hasChecked)
    {
        return;
    }

    if (c == num.size())
    {
        if (sumOfCD == v)
        {
            for (auto i : result)
            {
                cout << i << " ";
            }
            cout << "sum: " << sumOfCD << endl;
            hasChecked = true;
        }
    }
    else
    {
        result.push_back(num[c]);
        solve(c + 1, sumOfCD + num[c], v, num, result, hasChecked);
        result.pop_back();
        solve(c + 1, sumOfCD, v, num, result, hasChecked);
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
        int sum = accumulate(v.begin(), v.end(), 0);

        if (sum <= d)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << "sum: " << sum << endl;
        }
        else
        {
            vector<int> num;
            bool hasChecked = false;
            while (d--)
            {
                solve(0, 0, d + 1, v, num, hasChecked);
            }
        }
    }
}