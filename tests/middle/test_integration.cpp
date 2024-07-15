#include <catch2/catch_all.hpp>
#include "MathModule.h"
#include "StringUtils.h"

TEST_CASE("Integration Test: MathModule and StringUtils", "[middle]") {
    MathModule math;
    StringUtils stringUtils;

    SECTION("Addition and UpperCase") {
        int sum = math.add(2, 3);
        std::string result = stringUtils.toUpperCase("sum is " + std::to_string(sum));
        REQUIRE(result == "SUM IS 5");
    }

    SECTION("Multiplication and UpperCase") {
        int product = math.multiply(4, 5);
        std::string result = stringUtils.toUpperCase("product is " + std::to_string(product));
        REQUIRE(result == "PRODUCT IS 20");
    }
}
