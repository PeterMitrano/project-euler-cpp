#include <cmath>
#include <iostream>
#include <unordered_set>
#include <algorithm>

unsigned long problem() {
    constexpr auto const N{1'000'000'000ul};
    auto sum{0ul};
    auto x{7ul};
    auto h{4ul};

    while (2 * x < N) {

        if ((2 * x + 1) % 3 == 0) {
            // a + 1 case
            auto const a = (2 * x + 1) / 3;
            auto const perimeter = 3 * a + 1;
            if ((a + 1) * h % 2 == 0) {
                sum += perimeter;
            }
        } else if ((2 * x - 1) % 3 == 0) {
            // a - 1 case
            auto const a = (2 * x - 1) / 3;
            auto const perimeter = 3 * a - 1;
            if ((a + 1) * h % 2 == 0) {
                sum += perimeter;
            }
        }

        auto const temp = x;
        x = 2 * x + h * 3;
        h = h * 2 + temp;
    }

    return sum;
}