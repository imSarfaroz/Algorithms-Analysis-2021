#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    string num;
    getline(cin, num);
    int n;
    istringstream ss(num);
    ss >> n;
    getline(cin, num);
    while (n--)
    {
        vector<string> fragments;
        while (getline(cin, num) && !num.empty())
        {
            ss.clear();
            ss.str(num);
            string fragment;
            ss >> fragment;
            fragments.push_back(fragment);
        }

        // concetations
        map<string, int> memo;
        for (size_t i = 0; i < fragments.size(); ++i)
            for (size_t j = i + 1; j < fragments.size(); ++j)
            {
                ++memo[fragments[i] + fragments[j]];
                ++memo[fragments[j] + fragments[i]];
            }

        // Search for the string of highest count.
        map<string, int>::iterator iter(memo.begin());
        map<string, int>::iterator file(memo.begin());
        for (; iter != memo.end(); ++iter)
        {
            if (iter->second > file->second)
                file = iter;
        }
        cout << file->first << endl;
        if (n)
            cout << endl;
    }
}