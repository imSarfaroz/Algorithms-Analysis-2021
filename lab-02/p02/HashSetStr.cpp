#include "HashSetStr.hpp"
#include <iostream>

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

void HashSetStr::debugPrint() const
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        cout << i << ":";
        for (Node *p = buckets[i]; p != nullptr; p = p->mNext)
        {
            cout << " " << p->mData;
        }
        cout << endl;
    }
}

bool HashSetStr::find(const string &k)
{
    size_t index = mHash(k) % buckets.size();

    for (auto p = buckets[index]; p != nullptr; p = p->mNext)
    {
        if (p->mData == k)
        {
            return true;
        }
    }
    return false;
}

bool HashSetStr::erase(const string &k)
{
    size_t index = defaultHashFunc(k) % buckets.size();

    for (Node *pre = nullptr, *cur = buckets[index]; cur != nullptr;)
    {
        if (cur->mData == k)
        {
            if (pre != nullptr)
            {
                pre->mNext = cur->mNext;
            }
            else
            {
                buckets[index] = cur->mNext;
            }

            delete cur;
            --sz;
            return true;
        }
        pre = cur;
        cur = cur->mNext;
    }
    return false;
}

bool HashSetStr::insert(const string &k)
{
    size_t index = mHash(k) % buckets.size();

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
        index = mHash(k) % buckets.size();
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
            size_t index = mHash(buckets[i]->mData) % newBuckets.size();
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;
            t->mNext = newBuckets[index];
            newBuckets[index] = t;
        }
    }

    buckets.swap(newBuckets);
}

void HashSetStr::clear()
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i] != nullptr)
        {
            Node *t = buckets[i];
            buckets[i] = buckets[i]->mNext;
            delete t;
            --sz;
        }
    }
}
