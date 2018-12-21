#include <iostream>
#include <common/sqrt.h>
#include <common/sieve.h>

auto problem_003() {
    auto const n = 600851475143ull;
    auto n_i = n;
    auto const sqrt_n = integer_sqrt(n);
    auto const primes = prime_sieve<sqrt_n>();

    for (auto i = 2ull; i < n_i; ++i) {
        if (primes[i] == IS_PRIME) {
            if (n_i % i == 0) {
                n_i = n_i / i;
                i = 2ull;
            }
        }
    }

    return n_i;
}

int main() {
    std::cout << problem_003() << '\n';
    return 0;
}
