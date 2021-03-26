#pragma once

#include <cstddef>
#include <string>
#include <sstream>

template <typename T>
class List
{
    struct Node
    {
        Node *mPrev;
        Node *mNext;
        T mData;

        Node(const T &data, Node *prev, Node *next)
            : mData(data), mPrev(prev), mNext(next) {}
    };
    Node *head;
    std::size_t sz;

public:
    List()
        : head(new Node(T(), nullptr, nullptr)), sz(0)
    {
        head->mNext = head;
        head->mPrev = head;
    }

    ~List()
    {
        clear();
        delete head;
    }

    void clear()
    {
        while (begin() != end())
        {
            erase(begin());
        }
    }

    const size_t size() const
    {
        return sz;
    }

    std::string toStr() const
    {
        std::ostringstream out;
        out << "{";
        Node *p = head->mNext;
        for (std::size_t i = 0; i < sz; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->data;
            p = p->mNext;
        }
        out << "}";
        return out.str();
    }

    std::string toReverseStr() const
    {
        std::ostringstream out;
        out << "{";
        Node *p = head->mPrev;
        for (std::size_t i = 0; i < sz; i++)
        {
            if (i != 0)
            {
                out << ", ";
            }
            out << p->data;
            p = p->mPrev;
        }
        out << "}";
        return out.str();
    }

    //    void pushBack(const T &a) {

    //        Node* t = new Node(a, head->prev, head);
    //        t->prev->next = t;
    //        t->next->prev = t;
    //        sz++;
    //    }

    void pushBack(const T &a)
    {
        insert(end(), a);
    }

    void pushFront(const T &a)
    {
        insert(begin(), a);
    }

    void popBack()
    {
        Node *t = head->mPrev;
        t->mNext->mPrev = t->mPrev;
        t->mPrev->mNext = t->mNext;
        sz--;
        delete t;
    }

    void popFront()
    {
        Node *t = head->mNext;
        t->mNext->mPrev = t->mPrev;
        t->mPrev->mNext = t->mNext;
        sz--;
        delete t;
    }

    class Iter
    {
        friend class List<T>;
        Node *ptr;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        Iter()
            : ptr(nullptr)
        {
        }

        T &operator*() const
        {
            return ptr->mData;
        }

        Iter &operator++()
        {
            ptr = ptr->mNext;
            return *this;
        }

        Iter &operator++(int)
        {
            ptr = ptr->mNext;
            return *this;
        }

        Iter &operator--()
        {
            ptr = ptr->mPrev;
            return *this;
        }

        Iter &operator--(int)
        {
            ptr = ptr->mPrev;
            return *this;
        }

        T *operator->() const
        {
            return &(ptr->data);
        }

        bool operator==(const Iter &other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const Iter &other) const
        {
            return !(*this == other);
        }
    };

    class RIter
    {
        friend class List<T>;
        Node *ptr;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        RIter()
            : ptr(nullptr)
        {
        }

        T &operator*() const
        {
            return ptr->mData;
        }

        RIter &operator++()
        {
            ptr = ptr->mPrev;
            return *this;
        }

        RIter &operator++(int)
        {
            ptr = ptr->mPrev;
            return *this;
        }

        RIter &operator--()
        {
            ptr = ptr->mNext;
            return *this;
        }

        RIter &operator--(int)
        {
            ptr = ptr->mNext;
            return *this;
        }

        T *operator->() const
        {
            return &(ptr->data);
        }

        bool operator==(const RIter &other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const RIter &other) const
        {
            return !(*this == other);
        }
    };

    Iter begin()
    {
        Iter r;
        r.ptr = head->mNext;
        return r;
    }

    Iter end()
    {
        Iter r;
        r.ptr = head;
        return r;
    }

    RIter rbegin()
    {
        RIter r;
        r.ptr = head->mPrev;
        return r;
    }

    RIter rend()
    {
        RIter r;
        r.ptr = head;
        return r;
    }

    Iter erase(Iter p)
    {
        Iter r = p;
        r++;
        p.ptr->mPrev->mNext = p.ptr->mNext;
        p.ptr->mNext->mPrev = p.ptr->mPrev;
        delete p.ptr;
        --sz;
        return r;
    }

    Iter insert(Iter p, const T &x)
    {
        Iter t;
        t.ptr = new Node(x, p.ptr->mPrev, p.ptr);
        t.ptr->mNext->mPrev = t.ptr;
        t.ptr->mPrev->mNext = t.ptr;
        ++sz;
        return t;
    }
};