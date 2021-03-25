#include "MapStrInt.hpp"

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int &MapStrInt::operator[](const string &k)
{
    Node *pred = nullptr;
    Node *curr = mRoot;
    bool isLeft = false;
    while (curr != nullptr)
    {
        pred = curr;
        if (k < curr->mData.first)
        {
            isLeft = true;
            curr = curr->mLeft;
        }
        else if (curr->mData.first < k)
        {
            isLeft = false;
            curr = curr->mRight;
        }
        else
        {
            return curr->mData.second;
        }
    }

    Node *p = new Node(k, 0, nullptr, nullptr);

    ++mSize;

    if (mRoot == nullptr)
    {
        mRoot = p;
    }
    else if (isLeft)
    {
        pred->mLeft = p;
    }
    else
    {
        pred->mRight = p;
    }

    return p->mData.second;
}

void MapStrInt::printInOrder() const
{
    enum class Operation
    {
        goLeft,
        print,
        goRight,
        remove
    };

    vector<pair<Node *, Operation>> stack;

    stack.emplace_back(mRoot, Operation::goLeft);
    while (!stack.empty())
    {
        auto &back = stack.back();
        if (back.first == nullptr || back.second == Operation::remove)
        {
            stack.pop_back();
        }
        else if (back.second == Operation::goLeft)
        {
            back.second = Operation::print;
            stack.emplace_back(back.first->mLeft, Operation::goLeft);
        }
        else if (back.second == Operation::print)
        {
            back.second = Operation::goRight;
            cout << back.first->mData.first << ": " << back.first->mData.second << endl;
        }
        else if (back.second == Operation::goRight)
        {
            back.second = Operation::remove;
            stack.emplace_back(back.first->mRight, Operation::goLeft);
        }
    }
}