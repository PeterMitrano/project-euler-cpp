#include <catch2/catch.hpp>
#include <common/sieve.h>

TEST_CASE( "Prime Seive", "[sieve]" ) {
    auto const primes = prime_sieve<2088>();
    REQUIRE(sieve[0] == 1);
    REQUIRE(sieve[1] == 1);
    REQUIRE(sieve[2] == 0);
    REQUIRE(sieve[3] == 0);
    REQUIRE(sieve[4] == 1);
    REQUIRE(sieve[5] == 0);
    REQUIRE(sieve[6] == 1);
    REQUIRE(sieve[2083] == 0);
    REQUIRE(sieve[2084] == 1);
    REQUIRE(sieve[2085] == 1);
    REQUIRE(sieve[2086] == 1);
    REQUIRE(sieve[2087] == 0);
}
