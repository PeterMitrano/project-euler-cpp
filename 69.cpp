#include <array>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#include <common/sqrt.h>

struct Info {
    bool prime{true};
    std::vector<unsigned long> factors;
};

template<std::size_t Size>
auto unique_prime_factor_sieve() noexcept {
    // all bits will be zero-initialized. zero == prime, one == composite
    std::array<Info, Size> seive;

    // zero and one are not prime
    seive[0].prime = false;
    seive[1].prime = false;

    for (std::size_t potential_prime = 2; potential_prime < integer_sqrt(Size); ++potential_prime) {
        if (seive[potential_prime].prime) {
            std::size_t multiples = 2 * potential_prime;
            seive[potential_prime].factors.emplace_back(potential_prime);
            while (multiples < Size) {
                seive[multiples].prime = false;
                seive[multiples].factors.emplace_back(potential_prime);
                multiples += potential_prime;
            }
        }
    }

    return seive;
}

auto const sieve = unique_prime_factor_sieve<1'000'000>();

auto phi(unsigned long n) {
    auto totient_product = [&](double const &prod, unsigned long const &p) {
        return prod * (1 - 1.0 / p);
    };

    auto const factors = sieve[n].factors;
    auto const product = std::accumulate(factors.cbegin(), factors.cend(), 1.0, totient_product);
    return n * product;
}

unsigned long problem() {
    auto maximum_ratio{0.0};
    auto maximum_n{0ul};
    for (auto n{2ul}; n <= 1'000'000; ++n) {
        auto const ratio = static_cast<double>(n) / phi(n);
        if (ratio > maximum_ratio) {
            maximum_ratio = ratio;
            maximum_n = n;
        }
    }
    return maximum_n;
}