#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> words;
    string lines;
    string result = "";

    while(getline(cin, lines))
    {
        if(result[result.size() - 1] != '-')
        {
            result = "";
        }
        else
        {
            result.erase(result.end() - 1);
        }

        for (int i = 0; i < lines.size(); i++)
        {
            char w = lines[i];
            if (isalpha(w) || w == '-')
            {
                w = tolower(w);
                result += w;

                if(i == lines.size() - 1 && w != '-')
                {
                    words.insert(result);
                }
            }
            else
            {
                words.insert(result);
                result == "";
            }
        }
    }
    for(auto e : words)
    {
        if(!e.empty())
        {
            cout << e << endl;
        }
    }
    return 0;
}