#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int aX, int aY)
        : x(aX), y(aY)
    {
    }
};

// functor = functional object
struct CmpPoints
{
    bool operator()(const Point &p1, const Point &p2) const
    {
        if (p1.x != p2.x)
        {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }
};

using MapOfCaches = map<Point, vector<string>, CmpPoints>;

void insertCache(MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    for (string item; sinp >> item;)
    {
        caches[{x, y}].push_back(item);
    }
}

void checkCache(const MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    auto it = caches.find({x, y});
    if (it != caches.end())
    {
        for (const auto &e : it->second)
        {
            cout << " " << e;
        }
        cout << "\n";
    }
    else
    {
        cout << "Cache does not exist\n";
    }
}

void eraseCache(MapOfCaches &caches, istringstream &sinp)
{
    int x;
    sinp >> x;

    int y;
    sinp >> y;

    cout << (caches.erase({x, y}) ? "OK" : "Cache does not exist") << endl;
}

void printCaches(const MapOfCaches &caches)
{
    for (const auto &p : caches)
    {
        cout << "{" << p.first.x << ", " << p.first.y << "}:";
        for (const auto &item : p.second)
        {
            cout << " " << item;
        }
        cout << "\n";
    }
}

int main()
{
    MapOfCaches caches;

    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;

        if (cmd == "insert")
        {
            insertCache(caches, sinp);
        }
        else if (cmd == "check")
        {
            checkCache(caches, sinp);
        }
        else if (cmd == "erase")
        {
            eraseCache(caches, sinp);
        }
        else if (cmd == "print")
        {
            printCaches(caches);
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
}