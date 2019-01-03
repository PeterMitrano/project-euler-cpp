#include <catch2/catch.hpp>
#include <common/sqrt.h>

TEST_CASE("Integer Square Root", "[sqrt]") {
    for (auto i{1ul}; i < 10; ++i) {
        REQUIRE(integer_sqrt(i*i) == i);
    }
}
