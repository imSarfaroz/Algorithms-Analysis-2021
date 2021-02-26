#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numOfCase;
    cin >> numOfCase;

    for (int i = 0; i < numOfCase; i++)
    {
        multiset<int, greater<int>> gl;
        multiset<int, greater<int>> bl;

        int bf;
        cin >> bf;
        int g;
        cin >> g;
        int b;
        cin >> b;

        for (int j = 0; j < g; j++)
        {
            int temp;
            cin >> temp;
            gl.insert(temp);
        }

        for (int j = 0; j < b; j++)
        {
            int temp;
            cin >> temp;
            bl.insert(temp);
        }

        while (true)
        {
            if (bl.empty() || gl.empty())
            {
                break;
            }

            int battle = *gl.begin() - *bl.begin();

            bl.erase(bl.begin());
            gl.erase(gl.begin());

            if (battle < 0)
            {
                bl.insert(-battle);
            }
            else if (battle > 0)
            {
                gl.insert(battle);
            }
        }
    }
}

return 0;
}