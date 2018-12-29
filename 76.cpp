#include <vector>

unsigned int ways_to_write_as_sum(std::vector<unsigned int> parent_sums, unsigned int n) {
    auto ways{0u};
    for (auto s{1u}; s <= n / 2; ++s) {
        if (parent_sums.empty() or s >= parent_sums.back()) {
            parent_sums.push_back(s);
            ways += 1u + ways_to_write_as_sum(parent_sums, n - s);
        }
    }
    return ways;
}

unsigned long problem() {
    return ways_to_write_as_sum({}, 100);
}