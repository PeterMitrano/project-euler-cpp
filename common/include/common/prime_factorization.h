#pragma once

#include <common/sieve.h>
#include <vector>

template <std::size_t Size>
auto prime_factors(std::bitset<Size> primes, unsigned long n) {
    std::vector<unsigned long> factors;

    auto n_i = n;
    for (auto i = 2ull; i < n_i; ++i) {
        if (primes[i] == IS_PRIME) {
            if (n_i % i == 0) {
                factors.emplace_back(i);
                n_i = n_i / i;
                i = 1ull;
            }
        }
    }

    factors.emplace_back(n_i);
    return factors;
}

