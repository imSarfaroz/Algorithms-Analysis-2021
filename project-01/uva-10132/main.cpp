#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
    }
}