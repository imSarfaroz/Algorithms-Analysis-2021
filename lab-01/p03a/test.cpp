#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

#include "List.hpp"

TEST_CASE("constructor")
{
    List<int> v;

    REQUIRE(v.size() == 0);
}

TEST_CASE("pushback")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    REQUIRE(v.size() == 3);
    REQUIRE(v.toStr() == "{1, 2, 3}");
    REQUIRE(v.toReverseStr() == "{3, 2, 1}");
}

TEST_CASE("List<T>::Iter")
{
    List<int> v;

    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);

    auto it = v.begin();

    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(it == v.end());

    --it;
    REQUIRE(*it == 3);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 1);

    REQUIRE(it == v.begin());

    std::ostringstream out;
    for(auto e : v)
    {
        out << " " << e;
    }

    REQUIRE(out.str() == " 1 2 3");  
}
