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

        cin.ignore();

        string line;
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);  
            string w1, w2;
            ss >> w1 >> w2;

            // BFS
            queue<string> q;
            map<string, int> simWords;
            simWords[w1] = 0;
            q.push(w1);

            while (!q.empty() && simWords.count(w2) == 0)
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
                            if (u[j] != v[j])
                                ++diff;

                        if (diff == 1)
                        {
                            simWords[v] = simWords[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
            cout << w1 << " " << w2 << " " << simWords[w2] << endl;
        }
        if (num)
            cout << endl;
    }
}