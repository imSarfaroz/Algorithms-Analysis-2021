#pragma once

#include <cstddef>
#include <vector>
#include <string>

class HashSetStr
{
public:
    HashSetStr()
        : buckets(3, nullptr), sz(0)
    {
    }

    bool insert(const std::string &k);

    std::size_t size() const
    {
        return sz;
    }

    void debugPrint() const;

private:
    struct Node
    {
        std::string mData;
        Node *mNext;
        Node(const std::string &data, Node *next)
            : mData(data), mNext(next)
        {
        }
    };

    void rehash();

    std::vector<Node *> buckets;
    std::size_t sz;
};