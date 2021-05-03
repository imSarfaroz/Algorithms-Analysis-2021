#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "Algo.h"
#include <vector>

using namespace std;
TEST_CASE("Insertion Sort", "[byInsertion]")
{
    std::vector<int> v = {3, 4, 2, 1, 0, 5, 10, 7, 8, 9, 6};
    insertionSort(v);
    REQUIRE(v == "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}");
}
