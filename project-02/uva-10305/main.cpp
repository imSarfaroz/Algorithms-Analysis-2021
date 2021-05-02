#include <iostream>
#include <string>
#include <vector>

using namespace std;

int prob[100][100];
int vis[100];

void dfs(int z)
{
}

int main()
{
    int n;
    int m;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        int a;
        int b;

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            prob[a][b] = 1;
        }

        for (int i = 0; i <= n; i++)
        {
            if (vis[i] != 1)
            {
                dfs(i);
            }
        }
    }
}