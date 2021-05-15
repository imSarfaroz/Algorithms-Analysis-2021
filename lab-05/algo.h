#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>

std::string toStr(std::vector<int> &v);
void insertionSort(std::vector<int> &v);
int binarySearch(std::vector<int> &v, int x);
std::vector<int> mergeSort(std::vector<int> &v);
void quickSort(std::vector<int> &v, int p, int r);

#endif