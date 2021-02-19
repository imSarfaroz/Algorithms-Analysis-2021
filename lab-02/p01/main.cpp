#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct WorstHashFunction
{
    std::size_t operator()(const string &s) const
    {
        size_t r = 0;
        for (char e : s)
        {
            r += e;
        }

        return r;
    }
};

int main()
{
    unordered_set<string, WorstHashFunction> setOfWords;

    auto hash = setOfWords.hash_function();

    cout << "max load factor: " << setOfWords.max_load_factor() << endl;

    for (string line; getline(cin, line);)
    {
        istringstream sinp(line);

        cout << "Bucket count: " << setOfWords.bucket_count() << endl;
        string cmd;
        sinp >> cmd;

        if (cmd == "+")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << endl;
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << endl;
            auto p = setOfWords.insert(word);
            cout << (p.second ? "YES" : "NO") << endl;
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << endl;
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << endl;
            auto it = setOfWords.find(word);
            cout << (it != setOfWords.end() ? "YES" : "NO") << endl;
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hash(word) << endl;
            cout << "bucket's index: " << hash(word) % setOfWords.bucket_count() << endl;
            cout << (setOfWords.erase(word) ? "YES" : "NO") << endl;
        }
        else if (cmd == "#")
        {
            for (size_t i = 0; i < setOfWords.bucket_count(); ++i)
            {
                cout << setw(4) << i << ": ";
                for (auto p = setOfWords.begin(i); p != setOfWords.end(i); ++p)
                {
                    cout << " " << *p;
                }
                cout << endl;
            }
        }
    }
}