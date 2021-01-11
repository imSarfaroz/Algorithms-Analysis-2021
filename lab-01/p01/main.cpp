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
    if(head == nullptr)
    {
    head = tail = new Node(1, nullptr, nullptr);
    }
    else
    {
    tail->mNext = new Node(data, tail, nullptr);
    tail = tail->mNext;
    }
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
}