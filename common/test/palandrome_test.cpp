#include <catch2/catch.hpp>
#include <common/palandrome.h>

TEST_CASE("Palandrome", "[palandrom]") {
    REQUIRE(is_palandrome(1));
    REQUIRE(not is_palandrome(10));
    REQUIRE(is_palandrome(202));
    REQUIRE(not is_palandrome(300));
    REQUIRE(is_palandrome(5775));
}
