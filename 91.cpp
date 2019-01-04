#include <vector>
#include <map>
#include <cmath>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>

unsigned long problem() {
    constexpr auto const N{50ul};
    auto count{0ul};
    auto i{0ul};

    for (auto x1{1u}; x1 <= N; ++x1) {
        for (auto y1{0u}; y1 <= N; ++y1) {
            for (auto x2{0u}; x2 <= x1; ++x2) {
                for (auto y2{y1}; y2 <= N; ++y2) {
                    ++i;
                    auto const d1_squared = x2 * x2 + y2 * y2;
                    auto const d2_squared = x1 * x1 + y1 * y1;
                    auto const d0_squared = (x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1);
                    std::array<unsigned long, 3> squared_side_lengths{d0_squared, d1_squared, d2_squared};
                    std::sort(squared_side_lengths.begin(), squared_side_lengths.end());
                    auto const a_squared = squared_side_lengths[0];
                    auto const b_squared = squared_side_lengths[1];
                    auto const c_squared = squared_side_lengths[2];
                    if (a_squared == 0) {
                        continue;
                    }
                    else if (a_squared + b_squared == c_squared) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}