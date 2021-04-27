#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

void dfs(int v, const vector<vector<int>> &graph, vector<Color> &colors, vector<int> &order)
{
    colors[v] = Color::Red;

    for (auto &e : graph[v])
    {
        if(colors[e] == Color::Red)
        {
            throw runtime_error("Error: input is not a Directed Acyclic graph. Vertex: " + to_string(e + 1));
        }
        if (colors[e] == Color::White)
        {
            dfs(e, graph, colors, order);
        }
    }

    order.push_back(v);
    colors[v] = Color::Black;
}

int main()
try
{
    string line;

    getline(cin, line);
    int nVertices = stoi(line);
    vector<vector<int>> graph(nVertices);

    for (int i = 0; i < nVertices; i++)
    {
        getline(cin, line);
        if (line != "-")
        {
            istringstream sinp(line);
            for (int v; sinp >> v;)
            {
                graph[i].push_back(v - 1);
            }
        }
    }

    vector<Color> colors(nVertices, Color::White);

    vector<int> order;

    for (int i = 0; i < graph.size(); i++)
    {
        if (colors[i] == Color::White)
        {
            dfs(i, graph, colors, order);
        }
    }
    reverse(order.begin(), order.end());

    for (int e : order)
    {
        cout << " " << e + 1;
    }
    cout << "\n";
}
catch (runtime_error& e){
    cerr << e.what() << endl;
}
