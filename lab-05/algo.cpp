#include "Algo.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string toStr(vector<int> &v)
{
    string str = "{";

    for (int i = 0; i < v.size(); ++i)
    {
        str += to_string(v[i]);
        if (i != v.size() - 1)
        {
            str += ", ";
        }
    }
    str += "}";
    return str;
}

void insertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        int j = i;

        while (j > 0 and v[j] < v[j - 1])
        {
            int temp = v[j - 1];
            v[j - 1] = v[j];
            v[j] = temp;
            j = j - 1;
        }
    }
}

int binarySearch(vector<int> &v, int x)
{
    int p = 0;
    int r = v.size() - 1;
    while (p <= r)
    {
        int q = (p + r) / 2;
        if (v[q] == x)
        {
            return x;
        }
        if (v[q] > x)
        {
            r = q - 1;
        }
        else if (v[q] < x)
        {
            p = q + 1;
        }
    }
    return -1;
}

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> c;

    while (!a.empty() && !b.empty())
    {
        if (a[0] > b[0])
        {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else
        {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while (!a.empty() || !b.empty())
    {
        if (a.empty())
        {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else if (b.empty())
        {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }
    return c;
}

vector<int> mergeSort(std::vector<int> &v)
{
    if (v.size() == 1)
    {
        return v;
    }

    int p = 0;
    int r = v.size() - 1;
    int q = r / 2;

    vector<int> arrayOne;
    for (int i = p; i <= q; ++i)
    {
        arrayOne.push_back(v[i]);
    }
}