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
        for (int i = 0; i < lineOfWords.size(); i++)
        {
            char ch = lineOfWords[i];

            if(isalpha(ch))
            {
                ch = tolower(ch);
                result += ch;

                words.insert(result);
            }
        }
    }

    for(auto e : words)
    {
        cout << e << endl;
    }
}