#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>

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
            stringstream ss(line);
            string w1, w2;
            ss >> w1 >> w2;

            // BFS
            queue<string> q;
            map<string, int> simWords;
            q.push(w1);

            while (!q.empty())
            {
                string u = q.front();
                q.pop();
                // Need to have a loop to check every words
                for (size_t i = 0; i < words.size(); ++i)
                {
                    const string &v = words[i];
                    if (!simWords.count(v) && u.length() == v.length())
                    {
                        int diff = 0;
                        for (size_t j = 0; j < u.length(); ++j)
                            if (diff == 1)
                            {
                                // c
                            }
                    }
                }
            }
            cout << w1 << " " << w2 << endl;
        }
    }
}