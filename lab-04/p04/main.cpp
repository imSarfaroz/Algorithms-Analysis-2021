#include <iostream>

using namespace std;

void solve(int n, int source, int temp, int dest)
{
    if (n != 0)
    {
        solve(n - 1, source, dest, temp);
        cout << source << " -> " << dest << endl;
        solve(n - 1, temp, source, dest);
    }
}

int main()
{
    int n;
    cin >> n;

    solve(n, 1, 2, 3);
}