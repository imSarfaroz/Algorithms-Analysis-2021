#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

int main()
{
    int nEdges;
    cin >> nEdges;

    map<string, vector<string>> graph;
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

    queue<string, list<string>> q;
}