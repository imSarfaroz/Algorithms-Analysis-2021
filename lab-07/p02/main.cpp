#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

enum class State
{
    NotDefined,
    OnBorder,
    Intree
};

const int kNotDefined = -1;

int main()
{
    int nVer;
    cin >> nVer;

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

    vector<State> states(nVer, State::NotDefined);
    vector<int> distances(nVer, kNotDefined);
    vector<int> preds(nVer, kNotDefined);
    set<pair<int, int>> border;

    int total = 0;
    states[0] = State::Intree;
    for(auto v : graph[0])
    {
        states[v.first] = State::OnBorder;
        distances[v.first] = v.second;
        preds[v.first] = 0;
        border.emplace(v.second, v.first);  
    }

    for (int i = 1; i < nVer; ++i)
    {
        auto p = *border.begin();
        border.erase(border.begin());

        int u = preds[p.second];
        int v = p.second;
        int w = distances[v];

        cout << char(u + 'a') << " " << char(v + 'a') << " " << w << endl;
        total += w;

        states[v] = State::Intree;
        for(auto e: graph[v])
        {
            if (states[e.first] == State::NotDefined)
            {
                states[e.first] = State::OnBorder;
                distances[e.first] = e.second;
                preds[e.first] = v;
                border.emplace(e.second, e.first);
            }
            else if(states[e.first] == State::OnBorder && e.second < distances[e.first])
            {
                border.erase({distances[e.first], e.first});
                border.emplace(e.second, e.first);
                distances[e.first] = e.second;
                preds[e.first] = v;
            }
        }
    }
    
    cout << "Total weight: " << total << endl;
}