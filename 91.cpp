#include <vector>
#include <map>
#include <cmath>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wregister"

#include <common/matplotlibcpp.h>

#pragma GCC diagnostic pop

namespace plt = matplotlibcpp;

unsigned long problem() {
    constexpr auto const N{50ul};
    std::map<std::string, std::string> const kwargs{{"color", "red"}};
    auto count{0ul};
    auto i{0ul};
    auto x{0ul};
    auto y{0ul};

    auto const next_plot = [&]() {
        constexpr auto h{N};
        y += N + 1;
        if (y >= ((N + 1) * h)) {
            y = 0;
            x += N + 1;
        }
    };

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
//                    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
                    if (a_squared == 0) {
                        continue;
                    }
                    else if (a_squared + b_squared == c_squared) {
                        ++count;
//                        plt::plot(std::vector{x, x + x1, x + x2, x}, std::vector{y, y + y1, y + y2, y}, kwargs);
//                        next_plot();
                    }
                }
            }
        }
    }

//    plt::axis("equal");
//    plt::show();

//    std::cout << i << '\n';
    return count;
}