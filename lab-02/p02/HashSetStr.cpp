#include "HashSetStr.hpp"

using namespace std;

size_t defaultHashFunc(const string &s)
{
    size_t r = 0;
    for (auto c : s)
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
        if (p->mData == k)
        {
            return false;
        }
    }

    if (sz == buckets.size())
    {
        rehash();
        index = defaultHashFunc(k) % buckets.size();
    }

    buckets[index] = new Node(k, buckets[index]);

    ++sz;

    return true;
}

void HashSetStr::rehash()
{
    vector<Node *> newBuckets(2 * buckets.size() + 1, nullptr);

    for (size_t i = 0; i < buckets.size(); i++)
    {
        while (buckets[i] != nullptr)
        {
            size_t index = defaultHashFunc(buckets[i]->mData) % newBuckets.size();
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;
            t->mNext = newBuckets[index];
            newBuckets[index] = t;
        }
    }

    buckets.swap(newBuckets);
}
