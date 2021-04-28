#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

const string kNill = "no preds";

enum class Color
{
    White,
    Red,
    Black
};

int main()
{
    int nEdges;
    cin >> nEdges;

    map<string, vector<string>> graph;
    map<string, Color> states;
    // s : w, r
    // r : s, w

    for (int i = 0; i < nEdges; i++)
    {
        string v1;
        cin >> v1;

        string v2;
        cin >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    string src;
    cin >> src;

    string dst;
    cin >> dst;

    map<string, int> distances;
    map<string, string> preds;

    for (const auto &e : graph)
    {
        states[e.first] = Color::White;
        preds[e.first] = kNill;
    }

    queue<string> q;

    q.push(src);
    distances[src] = 0;
    states[src] = Color::Red;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        states[u] = Color::Black;
        for (const auto e : graph[u])
        {
            if (states[e] == Color::White)
            {
                states[e] = Color::Red;
                q.push(e);
                distances[e] = distances[u] + 1;
                preds[e] = u;
            }
        }
    }

    for (const auto &e : distances)
    {
        cout << e.first << ": " << e.second << endl;
    }

    cout << "----" << endl;
    for (const auto &e : preds)
    {
        cout << e.first << ": " << e.second << endl;
    }

    vector<string> path;
    string curVertex = dst;

    while (preds[curVertex] != kNill)
    {
        path.push_back(curVertex);
        curVertex = preds[curVertex];
    }

    path.push_back(src);

    reverse(path.begin(), path.end());
    for (const auto &e : path)
    {
        cout << " " << e;
    }
    cout << endl;
}