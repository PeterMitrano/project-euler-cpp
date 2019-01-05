#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#include <common/sieve.h>
#include <iostream>

unsigned int ways_to_write_as_sum_v2(std::vector<unsigned int> S, int n) {
    static std::map<std::pair<std::vector<unsigned int>, int>, unsigned int> memorization;
    auto const it = memorization.find(std::make_pair(S, n));
    if (it != memorization.cend()) {
        return it->second;
    }
    if (S.empty() or n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        auto sub_S = S;
        sub_S.pop_back();
        auto const result = ways_to_write_as_sum_v2(sub_S, n) + ways_to_write_as_sum_v2(S, n - S.back());
        memorization.emplace(std::make_pair(S, n), result);
        return result;
    }
}

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
