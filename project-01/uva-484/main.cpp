#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{

    vector<int> order;
    unordered_map<int, int> freq;

    int input;

    while (cin >> input)
    {

        if (freq[input] == 0)
        {
            order.emplace_back(input);
        }

        ++freq[input];
    }

    for (auto &o : order)
    {
        cout << o << " " << freq[o] << endl;
    }
}