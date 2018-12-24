#include <iostream>
#include <algorithm>
#include <optional>
#include <tuple>
#include <utility>

#include <common/sieve.h>
#include <common/digiterator.h>

unsigned long problem() {
    constexpr auto max = 1'000'000ul;
    constexpr auto desired_family_size = 8u;
    auto const primes = prime_sieve<max>();

    auto prime_replacement = [&](unsigned int const first_choice,
                                 unsigned int const second_choice,
                                 unsigned int const third_choice,
                                 unsigned long const p) {
        auto family_size = 0u;
        std::vector<unsigned long> members;
        Digiterator digiterator{p};
        for (auto replacement = 0u; replacement < 10u; ++replacement) {
            // we know that if it doesn't work with 0, 1, or 2, then it's not part of an eight digit family
            if (family_size == 0 and replacement > 2) {
                return std::pair{false, members};
            }

            if (replacement == 0u and first_choice == 0u) {
                continue;
            }

            digiterator[first_choice] = replacement;
            digiterator[second_choice] = replacement;
            digiterator[third_choice] = replacement;

            auto const new_p = digiterator.number();

            if (primes[new_p] == IS_PRIME) {
                ++family_size;
                members.push_back(new_p);
            }
        }

        return std::pair{family_size == desired_family_size, members};
    };

    auto has_digit_family = [&](unsigned long const p) {
        // we assume p is 6 digits
        // iterate over all choices of 3 spots out of 5
        for (auto first_choice = 0u; first_choice < 5; ++first_choice) {
            for (auto second_choice = first_choice + 1; second_choice < 5; ++second_choice) {
                if (second_choice == first_choice) {
                    continue;
                }
                for (auto third_choice = second_choice + 1; third_choice < 5; ++third_choice) {
                    if (third_choice == first_choice or third_choice == second_choice) {
                        continue;
                    }

                    auto result = prime_replacement(first_choice, second_choice, third_choice, p);
                    if (result.first) {
                        return result;
                    }
                }
            }
        }
        return std::pair<bool, std::vector<unsigned long>>{};
    };

    for (auto p = 100'000ul; p < max; ++p) {
        if (primes[p] == IS_PRIME) {
            bool has_family{false};
            std::tie(has_family, std::ignore) = has_digit_family(p);
            if (has_family) {
                return p;
            }
        }
    }
    return 0ul;
}
