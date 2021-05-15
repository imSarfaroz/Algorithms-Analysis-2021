#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "Algo.h"
#include <vector>

using namespace std;

TEST_CASE("Insertion Sort", "[byInsertion]")
{
    std::vector<int> v = {3, 4, 2, 1, 0, 5, 10, 7, 8, 9, 6};
    insertionSort(v);
    REQUIRE(toStr(v) == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}

TEST_CASE("Binary Search", "[Searching]")
{
    vector<int> v = {3, 4, 2, 1, 0, 5, 10, 7, 8, 9, 6};
    insertionSort(v);
    REQUIRE(binarySearch(v, 4) == 4);
    REQUIRE(binarySearch(v, 11) == -1);
}

TEST_CASE("Merge Sort", "[byMerging]")
{
    vector<int> v = {3, 4, 2, 1, 0, 5, 10, 7, 8, 9, 6};
    v = mergeSort(v);
    REQUIRE(toStr(v) == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}

TEST_CASE("quickSort()", "[SortBy_quickSort]")
{
    std::vector<int> v = {3, 4, 2, 1, 0, 5, 10, 7, 8, 9, 6};
    quickSort(v, 0, (v.size() - 1));
    REQUIRE(toStr(v) == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}
