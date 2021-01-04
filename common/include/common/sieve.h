#pragma once

#include <bitset>
#include <cmath>
#include <cstddef>
#include <vector>

extern int IS_PRIME;

template<std::size_t Size>
/** creates a lookup table for integers from 0 to Size indicating whether they are prime **/
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

template<std::size_t Size>
auto primes_list() {
    auto const sieve = prime_sieve<Size>();
    std::vector<unsigned int> primes;
    for (auto i=0u; i< Size; ++i)
    {
        if (!sieve[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
