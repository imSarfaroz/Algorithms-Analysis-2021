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