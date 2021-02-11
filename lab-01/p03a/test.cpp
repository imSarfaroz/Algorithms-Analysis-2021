#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include <utility>

#include "List.hpp"

TEST_CASE("constructor")
{
    List<int> v;

    REQUIRE(v.size() == 0);
}

TEST_CASE("pushback")
{
    List<int> v;

    REQUIRE(v.toStr() == "{}");
    REQUIRE(v.toReverseStr() == "{}");

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.toReverseStr() == "{3, 2, 1}");
}

TEST_CASE("clear")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");

    v.clear();

    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
}

TEST_CASE("List<T>::Iter")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();

    REQUIRE(it->first == 1);
    ++it;
    REQUIRE(it->first == 2);
    ++it;
    REQUIRE(it->first == 3);
    ++it;
    REQUIRE(it->first == v.end());

    --it;
    REQUIRE(it->second == 3);
    --it;
    REQUIRE(it->second == 2);
    --it;
    REQUIRE(it->second == 1);

    REQUIRE(it == v.begin());
}

TEST_CASE("erase")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto p = v.begin();
    ++p;

    p = v.erase(p);

    REQUIRE(v.size() == 2);
    REQUIRE(v.toStr() == "{1, 3}");
    REQUIRE(*p == 3);

    p = v.erase(p);
    REQUIRE(v.size() == 1);
    REQUIRE(v.toStr() == "{1}");
    REQUIRE(p == v.end());

    --p;
    p = v.erase(p);
    REQUIRE(v.size() == 0);
    REQUIRE(v.toStr() == "{}");
    REQUIRE(p == v.end());
}

TEST_CASE("insert")
{
    List<int> v;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto p = v.begin();
    ++p;
    p = v.insert(p, 0);

    REQUIRE(v.size() == 4);
    REQUIRE(v.toStr() == "{1, 0, 2, 3}");
    REQUIRE(*p == 0);
}