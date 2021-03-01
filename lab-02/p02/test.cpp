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

    REQUIRE(s.insert("C++"));
    REQUIRE(s.size() == 1);
    REQUIRE_FALSE(s.insert("C++"));

    REQUIRE(s.insert("C"));
    REQUIRE(s.size() == 2);
    REQUIRE_FALSE(s.insert("C"));

    REQUIRE(s.insert("JAVA"));
    REQUIRE(s.size() == 3);
    REQUIRE_FALSE(s.insert("JAVA"));

    REQUIRE(s.insert("Python"));
    REQUIRE(s.size() == 4);
    REQUIRE_FALSE(s.insert("Python"));
}