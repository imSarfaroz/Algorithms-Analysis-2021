#pragma once

#include <cstddef>
#include <vector>
#include <string>

std::size_t defaultHashFunc(const std::string &s);

class HashSetStr
{
public:
    using HashFunc = std::size_t (*)(const std::string &);

    HashSetStr(HashFunc hash = defaultHashFunc)
        : mHash(hash), buckets(3, nullptr), sz(0)
    {
    }

    ~HashSetStr()
    {
        clear();
    }

    bool insert(const std::string &k);
    bool find(const std::string &k);
    bool erase(const std::string &k);
    void clear();

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

    HashFunc mHash;
    std::vector<Node *> buckets;
    std::size_t sz;
};
