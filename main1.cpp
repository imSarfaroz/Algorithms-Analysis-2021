#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string mData;
    Node *mNext;

    Node(const string &data, Node *next)
        : mData(data), mNext(next)
    {
    }
};

int main()
{
    Node *head = nullptr;

    head = new Node("B", head); // allocate memory in the hip
    head = new Node("C", head);
    head = new Node("C++", head);

    for (auto p = head; p != nullptr; p = p->mNext)
    {
        cout << p->mData << endl;
    }
}