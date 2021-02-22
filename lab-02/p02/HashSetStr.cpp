#include "HashSetStr.hpp"

using namespace std;

size_t defaultHashFunc(const string &s)
{
    size_t r = 0;
    for(auto c : s)
    {
        r += c;
    }

    return r;
}

bool HashSetStr::insert(const string &k)
{
    size_t index = defaultHashFunc(k) % buckets.size();

    for (auto p = buckets[index]; p != nullptr; p = p->mNext)
    {
        if(p->mData == k)
        {
            return false;
        }
    }

    buckets[index] = new Node(k, buckets[index]);

    ++sz;

    return true;
}