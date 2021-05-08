#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class State
{
    NotDefined,
    OnBorder,
    Intree
};


int main()
{
    int nVer;
    cin >> nVer;

    vector<vector<pair<int, int>>> graph(9);
    char c1;
    char c2;
    int w;

    const int kNotDefined = -1;
     while (cin >> c1 >> c2 >> w)
    {
        int u = c1 - 'a';
        int v = c2 - 'a';

        graph[u].emplace_back(u, w);
        graph[v].emplace_back(u, w);
    }

    vector<State> states(nVer, State::NotDefined);
    vector<int> distances(nVer, kNotDefined);
    vector<int> preds(nVer, kNotDefined);
  

    int total = 0;
    states[0] = State::Intree;
    for(auto v : graph[0])
    {
        states[v.first] = State::OnBorder;
        distances[v.first] = v.second;
        preds[v.first] = 0;
    }

    for (int i = 1; i < nVer; ++i)
    {
        int indexMin = nVer;
        for (int j = 0; j < nVer; j++)
        {
            if(states[j] == State::OnBorder && (indexMin == nVer || distances[j] < distances[indexMin]))
            {
                indexMin = j;
            }
        }

        int u = preds[indexMin];
        int v = indexMin;
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
            }
            else if(states[e.first] == State::OnBorder && e.second < distances[e.first])
            {
                distances[e.first] = e.second;
                preds[e.first] = v;
            }
        }
    }
    
    cout << "Total weight: " << total << endl;
}