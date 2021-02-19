#include <iostream>
#include <unordered_map>

using namespace std;
//Just prume the list

int main()
{

    int testCase;
    cin >> testCase;
    int rCounter = 0;

    for (int i = 0; i < testCase; ++i)
    {

        unordered_map<int, int> aMap;
        unordered_map<int, int> bMap;

        int listA;
        int listB;
        cin >> listA;
        cin >> listB;

        for (int j = 0; j < listA; ++j)
        {
            int temp;
            cin >> temp;
            ++aMap[temp];
        }

        for (int j = 0; j < listB; ++j)
        {
            int temp;
            cin >> temp;
            if (aMap.find(temp) != aMap.end())
            {
                ++bMap[temp];
            }
            else
            {
                ++rCounter;
            }
        }
    }
}
