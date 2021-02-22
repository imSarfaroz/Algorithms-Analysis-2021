#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "HashSetStr.hpp"

TEST_CASE("constructor")
{
    HashSetStr s;

    REQUIRE(s.size() == 0);

}

TEST_CASE("insert")
{
    HashSetStr s;

    REQUIRE(s.insert("hello"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("hello"));
}