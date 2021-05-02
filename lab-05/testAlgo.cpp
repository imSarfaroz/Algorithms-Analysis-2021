#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include <vector>
#include "algo.h"

using namespace std;

TEST_CASE("insertion Sort")
{
    std::vector<int> v = {6, 5, 4, 3, 2, 1, 9, 8, 7, 10};
    insertionSort(v);
    REQUIRE(v == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}