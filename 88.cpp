#include <unordered_set>
#include <array>
#include <iostream>
#include <vector>
#include <numeric>

#include <common/sieve.h>

unsigned long problem() {
    constexpr auto const desired_k{12'000u};
    constexpr auto const n{2 * desired_k};
    auto const primes = prime_sieve<n + 1>();
    std::array<std::vector<std::vector<unsigned int>>, n + 1> factor_sets;
    for (auto i{2u}; i <= n; ++i) {
        // skip prime numbers, they always trivially satisfy the product-sum number where k=1
        if (primes[i] == IS_PRIME) {
            continue;
        }

        auto const m{std::sqrt(i)};
        for (auto factor{2u}; factor <= m; ++factor) {
            if (i % factor == 0u) {
                auto const remainder = i / factor;
                factor_sets[i].push_back({factor, remainder});
                if (remainder < i and primes[remainder] != IS_PRIME) {
                    for (auto alternative_factorization : factor_sets[remainder]) {
                        if (alternative_factorization.front() < factor) {
                            continue;
                        }
                        alternative_factorization.insert(alternative_factorization.begin(), factor);
                        factor_sets[i].emplace_back(alternative_factorization);
                    }
                }
            }
        }
    }

    auto N{0u};
    std::unordered_set<unsigned int> unique_ks;
    std::unordered_set<unsigned int> unique_Ns;
    std::array<unsigned int, n> Ns{0};
    for (const auto &factorizations : factor_sets) {
        if (primes[N] != IS_PRIME and N > 2) {
            for (const auto &factorization : factorizations) {
                auto const sum_of_factors = std::accumulate(factorization.cbegin(), factorization.cend(), 0u);
                auto const number_of_ones = N - sum_of_factors;
                auto const k = number_of_ones + factorization.size();
                // the first time you find a given k, not the N that corresponds to it
                if (Ns[k] == 0 and k <= desired_k) {
                    Ns[k] = N;
                    unique_ks.emplace(k);
                    unique_Ns.emplace(N);
                }
                if (unique_ks.size() == desired_k - 1) {
                    return std::accumulate(unique_Ns.cbegin(), unique_Ns.cend(), 0u);
                }
            }
        }
        ++N;
    }

    return 0ul;
}