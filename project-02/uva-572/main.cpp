#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int r, int c, vector<string> &grid)
{
    static const vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    static const vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    grid[r][c] = '|';

    for (int i = 0; i < 8; i++)
    {
        int tr = r + dr[i];
        int tc = c + dc[i];

        if (0 <= tr && tr < int(grid.size()) && 0 <= tc && tc < int(grid[0].size()) && grid[tr][tc] == '@')
        {
            dfs(tr, tc, grid);
        }
    }
}

int main()
{
    for (int h, w; cin >> h >> w && h != 0 && w != 0;)
    {
        vector<string> grid(h);

        for (int r = 0; r < h; r++)
        {
            cin >> grid[r];
        }

        int nComps = 0;
        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; ++c)
            {
                if (grid[r][c] == '@')
                {
                    ++nComps;
                    dfs(r, c, grid);
                }
            }
        }
        cout << nComps << "\n";
    }
}