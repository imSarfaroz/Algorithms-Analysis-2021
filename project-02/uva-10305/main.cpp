#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int prob[100][100];
int vis[100];

stack<int> s;

int n;
int m;

void dfs(int z)
{

    vis[z] = -1;

    for (int i = 1; i <= n; i++)
    {
        if (prob[z][i] == 1)
        {
            if (vis[i] == -1)
                return;
            else if (!vis[i])
                dfs(i);
        }
    }

    s.push(z);
    vis[z] = 1;
}

int main()
{

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

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] != 1)
            {
                dfs(i);
            }
        }

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }
    return 0;
}