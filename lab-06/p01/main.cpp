#include <iostream>
#include <vector>

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

void dfs(int v, const vector<vector<int>> &graph, vector<Color> &colors, vector<int> &component)
{
    colors[v] = Color::Red;

    component.push_back(v);

    for (auto &e : graph[v])
    {
        if (colors[e] == Color::White)
        {
            dfs(e, graph, colors, component);
        }
    }
}

int main()
{
    int nVertices;
    cin >> nVertices;

    vector<vector<int>> graph(nVertices);

    for (int r = 0; r < nVertices; r++)
    {
        for (int c = 0; c < nVertices; ++c)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
            {
                graph[r].push_back(c);
            }
        }
    }
    vector<Color> colors(nVertices, Color::White);

    int nComponents = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (colors[i] == Color::White)
        {
            ++nComponents;

            vector<int> curComponent;
            dfs(i, graph, colors, curComponent);

            cout << nComponents << ": ";

            for (auto e : curComponent)
            {
                cout << " " << endl;
            }
            cout << endl;
        }
    }
}
