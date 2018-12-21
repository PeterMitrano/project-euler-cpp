#include <iostream>
#include <common/sqrt.h>
#include <common/sieve.h>

auto problem_003() {
    auto answer{0};
    constexpr auto n = 600851475143;
    auto i = n;
    constexpr auto sqrt_n = integer_sqrt(n);
    auto primes = prime_sieve<sqrt_n>();

    for (const auto &p: primes) {
        if (i % p == 0) {
            i = i / p;
        }
    }

    return answer;
}

int main() {
    std::cout << problem_003() << '\n';
    return 0;
}
