#include <iostream>
#include <list>

using namespace std;

int main()
{
    for (string input; getline(cin, input);)
    {
        list<char> r;
        auto pos = r.end();
        for (auto c : input)
        {
            if (c == '[')
            {
                pos = r.begin();
            }
            else if (c == ']')
            {
                pos = r.end();
            }
            else
            {
                r.insert(pos, c);
            }
        }
        cout << string(r.begin(), r.end()) << endl;
    }
}