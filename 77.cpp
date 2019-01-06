#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#include <common/sieve.h>
#include <common/ways_to_write_as_sum.h>
#include <iostream>

unsigned long problem() {
    constexpr auto const maximum{5'000u};
    auto const sieve = prime_sieve<maximum - 1>();
    auto i{2ul};
    while (true) {
        std::vector<unsigned int> S;
        for (auto p{2u}; p < i; ++p) {
            if (sieve[p] == IS_PRIME) {
                S.push_back(p);
            }
        }
        auto const ways = ways_to_write_as_sum_v2(S, i);
        if (ways >= 5'000) {
            break;
        }
        ++i;
    }

    return i;
}
