#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<string> words;
    string lineOfWords;
    string result = "";

    while (getline(cin, lineOfWords))
    {
        if (result[result.size() - 1] != '-')
        {
            result = "";
        }
        else
        {
            result.erase(result.end() - 1);
        }

        for (int i = 0; i < lineOfWords.size(); i++)
        {
            char ch = lineOfWords[i];

            if (isalpha(ch))
            {
                ch = tolower(ch);
                result += ch;

                if (i == lineOfWords.size() - 1 && ch != '-')
                {
                    words.insert(result);
                }
            }
                else
                {
                    words.insert(result);
                   
                }
            }
        }

        for (auto e : words)
        {
                cout << e << endl;   
        }

    return 0;
}