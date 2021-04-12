#pragma once

#include <string>
#include <utility>
#include <ostream>

class MapStrInt
{
public:
    MapStrInt()
        : mRoot(nullptr), mSize(0)
    {
    }

    ~MapStrInt()
    {
        clear();
    }

    void clear()
    {
        clear(mRoot);
    }

    int &operator[](const std::string &k);

    // might cause stackoverflow
    void printInOrder(std::ostream &out) const
    {
        printInOrder(out, mRoot);
    }

    std::size_t size() const
    {
        return mSize;
    }

private:
    struct Node
    {
        std::pair<std::string, int> mData;
        Node *mLeft;
        Node *mRight;

        Node(const std::string &k, int v, Node *left, Node *right)
            : mData(k, v), mLeft(left), mRight(right)
        {
        }
    };

    void clear(Node *root);

    void printInOrder(std::ostream &out, Node *root) const;
    Node *mRoot;
    std::size_t mSize;
};