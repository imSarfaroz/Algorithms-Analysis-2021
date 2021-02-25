#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numOfdays;
    cin >> numOfdays;

    while (numOfdays != 0)
    {
        set<int> box;

        for (int i = 0; i < numOfdays; i++)
        {
            int ticketsAdded;
            cin >> ticketsAdded;

            for (int i = 0; i < ticketsAdded; i++)
            {
                int temp;
                cin >> temp;
                box.insert(temp);
            }

            // retult
            // erase box
            // print
        }
    }
}