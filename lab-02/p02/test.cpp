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

    s.debugPrint();

    REQUIRE(s.insert("C"));
    REQUIRE(s.size() == 2);
    REQUIRE_FALSE(s.insert("C"));

    s.debugPrint();

    REQUIRE(s.insert("JAVA"));
    REQUIRE(s.size() == 3);
    REQUIRE_FALSE(s.insert("JAVA"));

    s.debugPrint();

    REQUIRE(s.insert("Python"));
    REQUIRE(s.size() == 4);
    REQUIRE_FALSE(s.insert("Python"));

    s.debugPrint();
}

TEST_CASE("erase")
{
    std::cout << "----" << std::endl;

    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("C#");
    s.insert("Go");
    s.insert("Rust");
    s.insert("Python");
    s.insert("Ruby");
    s.insert("Kotlin");

    s.debugPrint();

    REQUIRE_FALSE(s.erase("Hello"));
    REQUIRE_FALSE(s.erase("World"));

    REQUIRE(s.erase("C++"));
    s.debugPrint();

    REQUIRE(s.erase("C"));
    s.debugPrint();

    REQUIRE(s.erase("Java"));
    s.debugPrint();

    REQUIRE(s.erase("C#"));
    s.debugPrint();

    REQUIRE(s.erase("Go"));
    s.debugPrint();

    REQUIRE(s.erase("Rust"));
    s.debugPrint();

    REQUIRE(s.size() == 3);
}
TEST_CASE("clear")
{

    HashSetStr s;

    s.insert("C++");
    s.insert("C");
    s.insert("Java");
    s.insert("C#");
    s.insert("Go");
    s.insert("Rust");
    s.insert("Python");
    s.insert("Ruby");
    s.insert("Kotlin");

    s.clear();
    REQUIRE(s.size() == 0);

    std::cout << "---after clear---" << std::endl;

    s.debugPrint();
}
