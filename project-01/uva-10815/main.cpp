#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

int main()
{
    set<string> r;
    string w;
    for (char c; cin.get(c);)
    {
        if(isalpha(c))
        {
            w += tolower(c);
        }
        else if (!w.empty())
        {
            r.insert(w);
            w.clear();
        }
    }
    if(!w.empty())
    {
        r.insert(w);
    }

    for(const auto &e : r)
    {
        cout << e << "\n";
    }
}