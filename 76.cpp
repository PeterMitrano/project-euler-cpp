#include <vector>
#include <utility>

unsigned int ways_to_write_as_sum_v1(std::vector<unsigned int> parent_sums, unsigned int n) {
    auto ways{0u};
    for (auto s{1u}; s <= n / 2; ++s) {
        if (parent_sums.empty() or s >= parent_sums.back()) {
            parent_sums.push_back(s);
            ways += 1u + ways_to_write_as_sum_v1(parent_sums, n - s);
        }
    }
    return ways;
}

unsigned int ways_to_write_as_sum_v2(std::vector<unsigned int> S, int n) {
    if (S.empty() or n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else {
        auto sub_S = S;
        sub_S.pop_back();
        return ways_to_write_as_sum_v2(sub_S, n) + ways_to_write_as_sum_v2(S, n - S.back());
    }
}

unsigned long problem() {
    constexpr auto const n{100u};
    std::vector<unsigned int > S;
    for (auto i{1u}; i < n; ++i) {
        S.push_back(i);
    }
    return ways_to_write_as_sum_v2(S, n);
}