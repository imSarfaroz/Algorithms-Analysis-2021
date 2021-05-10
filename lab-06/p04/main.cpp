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
        if (cStart != string::npos)
        {
            start = r * mazeSize + cStart;
        }
        int cDest = maze[r].find('D');
        if (cStart != string::npos)
        {
            dest = r * mazeSize + cStart;
        }
    }
    vector<int> distances(mazeSize * mazeSize);
    vector<int> preds(mazeSize * mazeSize, kNoPred);
    vector<Color> colors(mazeSize * mazeSize, Color::White);

    queue<int> q;
    q.push(start);
    colors[start] = Color::Red;
    distances[start] = 0;

    while (!q.empty())
    {
    }
}