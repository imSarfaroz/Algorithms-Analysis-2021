#pragma once

#include <cstddef>
#include <string>
#include <sstream>

#template < typename T>
class List
{

    struct Node
    {
        Node *mPrev;
        Node *mNext;
        T mData;

        Node(const T &data, Node *prev, Node *next)
            : mPrev(prev), mNext(next), mData(data)
        {
        }
    };

    Node *mHead;
    Node *mTail;
    std::size_t mSize;

public:
    List()
        : mHead(new Node(T(), nullptr, nullptr)), mTail(new Node(T(), nullptr, nullptr)), mSize(0)
    {
        mHead->mNext = mTail;
        mTail->mPrev = mHead;
    }

    std::size_t size() const
    {
        return mSize;
    }

    std::string toStr() const
    {
        std::ostreamstream out;
        out << "{";
        Node *p = mHead->mNext;
        for (std::size_t i = 0; i < mSize; ++i)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mNext;
        }
        out << "}";

        return out.str();
    }

    std::string toReverseStr() const
    {
        std::ostreamstream out;
        out << "{";
        Node *p = mTail->mPrev;
        for (std::size_t i = 0; i < mSize; ++i)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->mData;
            p = p->mPrev;
        }
        out << "}";
        return out.str();
    }

    void pushBack(const T &x)
    {
        Node *t = new Node(x, mTail->mPrev, mTail);
        mTail->mPrev->mNext = t;
        mTail->mPrev = t;
        ++mSize;
    }

    class Iter
    {
    };
