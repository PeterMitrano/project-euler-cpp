#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#include <common/ways_to_write_as_sum.h>

unsigned long problem() {
    constexpr auto const n{100u};
    std::vector<unsigned int > S;
    for (auto i{1u}; i < n; ++i) {
        S.push_back(i);
    }
    return ways_to_write_as_sum_v2(S, n);
}