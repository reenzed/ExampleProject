#include <catch2/catch_all.hpp>
#include "MockBase.h"

TEST_CASE("Mock object test with Trompeloeil", "[mock]") {
    MockBase mock;
    REQUIRE_CALL(mock, foo(42)); // Waiting for function foo to be called with argument 42

    SECTION("Calling foo with 42") {
        mock.foo(42); // call
    }
}
