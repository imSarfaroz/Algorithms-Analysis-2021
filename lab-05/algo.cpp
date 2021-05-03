#include "Algo.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


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