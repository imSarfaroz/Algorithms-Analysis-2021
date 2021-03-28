#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int numOfCases;
    cin >> numOfCases;

    for (int i = 0; i < numOfCases; i++)
    {
        unordered_map<string, int> sub;

        int HW;
        cin >> HW;

        for (int j = 0; j < HW; j++)
        {
            string sb;
            cin >> sb;
            int time;
            cin >> time;

            sub[sb] = time;
        }

        int cmpTime;
        cin >> cmpTime;

        string HWsb;
        cin >> HWsb;

        cout << "Case " << i + 1 << ": ";

        if (sub.find(HWsb) == sub.end() || sub[HWsb] > (cmpTime + 5))
        {
            cout << "Do your own homework!" << endl;
        }
        else if (sub[HWsb] <= cmpTime)
        {
            cout << "Yesss" << endl;
        }
        else if (sub[HWsb] <= (cmpTime + 5))
        {
            cout << "Late" << endl;
        }
    }
}
