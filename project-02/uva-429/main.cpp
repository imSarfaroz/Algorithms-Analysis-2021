#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;

    while (num--)
    {
        vector<string> words;

        string word;
        while (cin >> word && word != "*")
        {
            words.push_back(word);
        }

        string line;
        while (getline(cin, line))
        {
        }
    }
}