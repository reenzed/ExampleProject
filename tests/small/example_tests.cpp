#include <catch2/catch_all.hpp>
#include "add.h"

TEST_CASE("Unit-test (TDD): Testing the addition function", "[small]") {
    REQUIRE(Add(2, 2) == 4);
}

SCENARIO("Small (BDD): User can add numbers", "[small]") {
    GIVEN("Two numbers") {
        int x = 2;
        int y = 3;

        WHEN("they add up") {
            int result = Add(x, y);

            THEN("the result must be their sum") {
                REQUIRE(result == 5);
            }
        }
    }
}
