#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    for (int h, w; cin >> h >> w && h != 0 && w != 0)
    {
        vector<string> grid(h);

        for (int r = 0; r < h; r++)
        {
            cin >> grid[r];
        }
    }
}