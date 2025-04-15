#include <catch2/catch_test_macros.hpp>

#include "exercise/math.h"


TEST_CASE("compile time calculate")
{

    SECTION("is_prime")
    {
        REQUIRE(exercise::is_prime(7));
        REQUIRE_FALSE(exercise::is_prime(10));
    }

    SECTION("is_odd")
    {
        REQUIRE(exercise::is_odd(1));
        REQUIRE_FALSE(exercise::is_odd(10));
    }

    SECTION("is_even")
    {
        REQUIRE(exercise::is_even(2));
    }
}