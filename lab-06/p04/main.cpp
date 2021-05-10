#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

const int kNoPred = -1;

bool inside(const vector<string> &maze, int r, int c)
{
    int h = maze.size();
    int w = maze[0].size();
    return 0 <= r && r < h && 0 <= c && c < w;
}

int main()
{
    int mazeSize;
    cin >> mazeSize;

    vector<string> maze(mazeSize);
    int start;
    int dest;
    for (int r = 0; r < mazeSize; r++)
    {
        cin >> maze[r];
        int cStart = maze[r].find("S");
        if (cStart != int(string::npos))
        {
            start = r * mazeSize + cStart;
        }
        int cDest = maze[r].find('D');
        if (cDest != int(string::npos))
        {
            dest = r * mazeSize + cDest;
        }
    }
    vector<int> distances(mazeSize * mazeSize);
    vector<int> preds(mazeSize * mazeSize, kNoPred);
    vector<Color> colors(mazeSize * mazeSize, Color::White);

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    queue<int> q;
    q.push(start);
    colors[start] = Color::Red;
    distances[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        colors[cur] = Color::Black;

        int r = cur / mazeSize;
        int c = cur % mazeSize;
        for (int i = 0; i < int(dr.size()); ++i)
        {
            int tr = r + dr[i];
            int tc = c + dc[i];
            int t = tr * mazeSize + tc;
            if (inside(maze, tr, tc) && maze[tr][tc] != '#' && colors[t] == Color::White)
            {
                q.push(t);
                colors[t] = Color::Red;
                preds[t] = cur;
                distances[t] = distances[cur] + 1;
                if (t == dest)
                {
                    goto breakForWhile;
                }
            }
        }
    }

breakForWhile:
    if (preds[dest] == kNoPred)
    {
        cout << "Unreachable\n";
    }
    else
    {
        cout << distances[dest] << "\n";
        int cur = dest;
        while (cur != start)
        {
            maze[cur / mazeSize][cur % mazeSize] = '*';
            cur = preds[cur];
        }
        for (const auto e : maze)
        {
            cout << e << "\n";
        }
    }
}