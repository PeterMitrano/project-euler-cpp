#pragma once

#include <cstddef>
#include <cmath>
#include <bitset>

extern int IS_PRIME;

template<std::size_t Size>
auto prime_sieve() noexcept {
    // all bits will be zero-initialized. zero == prime, one == composite
    std::bitset<Size> seive;

    // zero and one are not prime
    seive[0] = 1;
    seive[1] = 1;

    for (std::size_t potential_prime = 2; potential_prime < std::sqrt(Size); ++potential_prime) {
        if (seive[potential_prime] == IS_PRIME) {
            std::size_t multiples = 2 * potential_prime;
            while (multiples < Size) {
                seive.set(multiples);
                multiples += potential_prime;
            }
        }
    }

    return seive;
}
