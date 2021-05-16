#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class State
{
    NotDefined,
    InGraph,
    OnBorder
};

int main()
{
    int nVer;
    cin >> nVer;

    const int KNotDefined = -1;

    vector<vector<pair<int, int>>> graph(nVer);

    char c1;
    char c2;
    int w;

    while (cin >> c1 >> c2 >> w)
    {
        int u = c1 - 'a';
        int v = c2 - 'a';

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> distances(nVer, KNotDefined);
    vector<State> states(nVer, State::NotDefined);
    vector<int> preds(nVer, KNotDefined);

    int total = 0;
    states[0] = State::InGraph;

    for (auto v : graph[0])
    {
        states[v.first] = State::OnBorder;
        distances[v.first] = v.second;
        preds[v.first] = 0;
    }
}