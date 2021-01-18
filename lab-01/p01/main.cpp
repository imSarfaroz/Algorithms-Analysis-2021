#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node
{
    int mData;
    Node *mPrev;
    Node *mNext;

    Node(int data, Node *prev, Node *next)
        : mData(data), mPrev(prev), mNext(next)
    {
    }
};

void printInDirectOrder(Node *head)
{
    for (Node *p = head; p; p = p->mNext)
    {
        cout << " " << p->mData;
    }
    cout << endl;
}

void printInReversedMode(Node *tail)
{
    for (Node *p = tail; p; p = p->mPrev)
    {
        cout << " " << p->mData;
    }
    cout << endl;
}

void pushBack(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data, nullptr, nullptr);
    }
    else
    {
        tail->mNext = new Node(data, tail, nullptr);
        tail = tail->mNext;
    }
}

void clear(Node *&head, Node *&tail)
{
    for (Node *p = head; p != nullptr;)
    {
        Node *t = p->mNext;
        delete p;
        p = t;
    }

    head = tail = nullptr;
}

void insertBefore(Node *&head, Node *cur, int data)
{
    if (head == cur)
    {
        cur->mPrev = new Node(data, nullptr, cur);
        head = cur->mPrev;
    }
    else
    {
        Node *t = new Node(data, cur->mPrev, cur);
        t->mPrev->mNext = t;
        t->mNext->mPrev = t;
    }
}

Node *erase(Node *&head, Node *&tail, Node *cur)
{
    if (cur == tail && head == tail)
    {
        delete head;
        head = tail = nullptr;
        return nullptr;
    }
    else if (head == cur)
    {
        head = head->mNext;
        head->mPrev = nullptr;
        delete cur;
        return head;
    }
    else if (cur == tail)
    {
        tail = tail->mPrev;
        tail->mPrev = nullptr;
        delete cur;
        return nullptr;
    }

    Node *t = cur->mNext;
    cur->mPrev->mNext = cur->mNext;
    cur->mNext->mPrev = cur->mPrev;
    delete cur;
    return t;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int x; cin >> x;)
    {
        pushBack(head, tail, x);
    }

    printInDirectOrder(head);
    printInReversedMode(tail);

    for (Node *p = head; p != nullptr; p = p->mNext)
    {
        if (p->mData % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }

    printInDirectOrder(head);
    printInReversedMode(tail);

    for (Node *p = head; p != nullptr;)
    {
        if (p->mData % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->mNext;
        }
    }

    printInDirectOrder(head);
    printInReversedMode(tail);

    clear(head, tail);
}