#include <iostream>
#include <vector>
#include <set>
using namespace std;

int numOfVer, numOfEdges;
vector<vector<int>> edges;

bool isConnected()
{
    if (numOfVer == 1)
        return 1;

    int been[numOfVer];
    for (int i = 0; i < numOfVer; ++i)
        been[i] = 0;

    int here;

    vector<int> queue = (numOfVer > 0 ? vector<int>(1, 0) : vector<int>(0));
    while (!queue.empty())
    {
        here = queue.back();
        queue.pop_back();
        for (const int &e : edges[here])
        {
            if (!been[e])
                queue.push_back(e);

            been[e] = 1;
        }
    }

    for (int i = 0; i < numOfVer; ++i)
    {
        if (!been[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int ver, edg;
    string type;

    cout << "Num of Vertices: ";
    cin >> numOfVer;

    if (numOfVer == 0)
    {
        numOfEdges = 0;
    }
    else
    {
        cout << "Num of Edges: ";
        cin >> numOfEdges;
    }

    cout << "Type of graph: ";

    while (cin >> type)
    {
        if (type == "directed" || type == "undirected")
        {
            break;
        }
        else
        {
            cout << "choose 'directed' or 'undirected'." << endl;
        }
    }

    edges = vector<vector<int>>(numOfVer, vector<int>());
    int again = 0;
    for (int i = 0; i < numOfEdges; ++i)
    {
        again = 0;
        cout << "provide the edge #" << i << " (x y): ";
        do
        {
            if (again)
            {
                cout << "please, don't joke around! ";
            }
            cout << "0 <= value < " << numOfVer << "\n";
            cin >> ver >> edg;
            again = 1;

        } while (!(ver >= 0 && ver < numOfVer && edg >= 0 && edg < numOfVer));
        edges[ver].push_back(edg);

        if (type == "undirected")
        {
            edges[edg].push_back(ver);
        }
    }

    if (isConnected())
    {
        cout << "The graph is connected!\n";
    }
    else
    {
        cout << "The graph is disconnected!\n";
    }
}
