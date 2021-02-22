#pragma once

#include <cstddef>
#include <vector>
#include <string>

class HashSetStr
{
public:
    HashSetStr()
    : buckets(11, nullptr), sz(0)
    {    
    } 

    bool insert(const std::string &k);

    std::size_t size() const
    {
        return sz;
    }

private:
    struct Node
    {
        std::string mData;
        Node *mNext;
        Node(const std::string &data, Node *next)
        :mData(data), mNext(next)
        {
        }
    };

    std::vector<Node*> buckets;
    std::size_t sz;
};