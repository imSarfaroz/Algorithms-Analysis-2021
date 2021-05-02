#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int v;
    int e;
    vector<vector<int>> edjes;

    int contains(int in, int out);
    int undir();
    int weakCheck();
    int strongCheck();
    int readAdj();
    int readEdj();

    void resetEdjes() { edjes = vector<vector<int>>(v, vector<int>(0)); }
    vector<vector<int>> fillReverseEdj();
    int dfs(int x);

public:
    Graph() : v(0), e(0), edjes(vector<vector<int>>(0)) {}
    Graph(int nv, int ne) : v(nv), e(ne), edjes(vector<vector<int>>(nv, vector<int>(0))) {}
    ~Graph()
    {
        v = 0;
        e = 0;
        edjes.clear();
    }

    int fill(string filltype);
    int check();
};

int main()
{
    int verticies, edjes;
    cout << "Provide Vertices and edges: [v e]\n";
    cin >> verticies >> edjes;

    Graph g(verticies, edjes);

    string fillType;
    int fail = 0;
    do
    {
        cout << "provide filling data style: (adjMatrix/edges)\n";
        cin >> fillType;
        if (cin.fail())
        {
            cout << "Reading fail\n";
            return 0;
        }
    } while (!g.fill(fillType));

    int connectivity = g.check();

    switch (connectivity)
    {
    case 0:
        cout << "Not connected.\n";
        break;
    case 1:
        cout << "Weakly connected.\n";
        break;
    case 2:
        cout << "Strongly connected.\n";
        break;
    case 3:
        cout << "Connected (undirected).\n";
        break;
    default:
        cout << "Error. (returned " << connectivity << ")\n";
        break;
    };
    return 0;
}

int Graph::fill(string filltype)
{
    if (filltype == "adjMatrix")
        return readAdj();
    else if (filltype == "edges")
        return readEdj();
    else
        return 0;
    return 1;
}

int Graph::readAdj()
{
    int c;
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            // DEBUG: cout << i << " to " << j << ": ";
            if (cin >> c)
            {
                // DEBUG: cout << "   I have read " << c << "\n";
                if (c != 0)
                {
                    edjes[i].push_back(j);
                }
            }
            else
            {
                cout << "Reading error.\n";
                resetEdjes();
                return 0;
            }
            //DEBUG: cout << "\n";
        }
    }
    return 1;
}

int Graph::readEdj()
{
    int in, out;
    for (int i = 0; i < e; ++i)
    {
        if (cin >> in >> out)
        {
            if (in > 0 && in <= v && out > 0 && out <= v)
            {
                edjes[in - 1].push_back(out - 1);
            }
            else
            {
                cout << "Incorrect input!\n";
                i--;
            }
        }
        else
        {
            cout << "Reading error.\n";
            resetEdjes();
            return 0;
        }
    }
    return 1;
}

int Graph::check()
{
    if (v == 0 || v == 1)
    {
        return 2;
    }

    int count = 0;
    count += weakCheck();
    if (count)
    {
        if (undir())
        {
            return 3; //undirected connected
        }
        count += strongCheck();
    }
    else
        return 0; //no connection

    return count;
    // 1: weak connection
    // 2: strong connection
}
int Graph::contains(int in, int out)
{
    for (const auto &n : edjes[in])
    {
        if (n == out)
            return 1;
    }
    return 0;
}

int Graph::undir()
{
    for (int in = 0; in < v; ++in)
    {
        for (const auto &out : edjes[in])
        {
            if (!contains(out, in))
                return 0;
        }
    }
    return 1;
}

int Graph::weakCheck()
{
    vector<vector<int>> rEdj = fillReverseEdj();

    vector<int> q(1, 0);
    vector<int> been(v, 0);
    been[0] = 1;
    int cnt = 1;
    int here;
    while (!q.empty())
    {
        here = q.back();
        q.pop_back();
        for (const auto &n : edjes[here])
        {
            if (!been[n])
            {
                q.push_back(n);
                been[n] = 1;
                cnt++;
            }
        }
        for (const auto &n : rEdj[here])
        {
            if (!been[n])
            {
                q.push_back(n);
                been[n] = 1;
                cnt++;
            }
        }
    }
    if (cnt == v)
        return 1;
    return 0;
}

vector<vector<int>> Graph::fillReverseEdj()
{
    vector<vector<int>> r(v, vector<int>(0));
    for (int in = 0; in < v; ++in)
    {
        for (const auto &out : edjes[in])
        {
            r[out].push_back(in);
        }
    }
    return r;
}

int Graph::strongCheck()
{
    for (int i = 0; i < v; ++i)
    {
        // DEBUG: cout << "strong Check: i = " << i << "\t";
        if (!dfs(i))
            return 0;
        // DEBUG: cout << "success...\n";
    }
    return 1;
}

int Graph::dfs(int x)
{
    // DEBUG: cout << "\n inside " << x << "\n";
    vector<int> q(1, x);
    vector<int> been(v, 0);
    been[x] = 1;
    int cnt = 1;
    while (!q.empty())
    {
        x = q.back();
        q.pop_back();
        // DEBUG: cout << "  checking connections from " << x << ":\t";
        for (const auto &n : edjes[x])
        {
            if (!been[n])
            {
                // DEBUG: cout << " " << n;
                q.push_back(n);
                been[n] = 1;
                cnt++;
            }
        }
        // DEBUG: cout << "\n";
    }
    if (cnt == v)
        return 1;
    return 0;
}
