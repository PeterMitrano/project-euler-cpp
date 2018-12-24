#include <catch2/catch.hpp>
#include <common/digiterator.h>

TEST_CASE("Num Digits", "[digits]") {
    REQUIRE(num_digits(1) == 1);
    REQUIRE(num_digits(9) == 1);
    REQUIRE(num_digits(10) == 2);
    REQUIRE(num_digits(19) == 2);
    REQUIRE(num_digits(1234567) == 7);
}

TEST_CASE("Iterate over Digits", "[digits]") {
    Digiterator digits(123456789123);
    REQUIRE(digits[0] == 1);
    REQUIRE(digits[1] == 2);
    REQUIRE(digits[2] == 3);
    REQUIRE(digits[8] == 9);
    REQUIRE(digits[9] == 1);
    REQUIRE(digits[10] == 2);
    REQUIRE(digits[11] == 3);
}

TEST_CASE("Edit Digits", "[digits]") {
    Digiterator digits(12345);
    REQUIRE(digits.number() == 12345);
    digits[3] = 0;
    REQUIRE(digits.number() == 12305);
    digits[0] = 0;
    REQUIRE(digits.number() == 2305);
    digits[0] = 9;
    REQUIRE(digits.number() == 92305);
}
