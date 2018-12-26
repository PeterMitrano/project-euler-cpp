#include <cmath>
#include <iostream>
#include <common/fabs.h>
#include <common/digiterator.h>

constexpr auto find_period(unsigned long const S, unsigned long const a0) {
    auto m{0ul};
    auto d{1ul};
    auto a{a0};

    auto i{0ul};
    while (a != 2.0 * a0) {
        m = d * a - m;
        d = (S - m * m) / d;
        a = (a0 + m) / d;
        ++i;
    }

    return i;
};

unsigned long problem() {
    auto num_fractions_with_odd_period{0ul};
    for (auto n{2ul}; n <= 10'000ul; ++n) {
        auto const root = std::sqrt(n);
        double intpart;
        if (std::modf(root, &intpart) != 0) {

            auto const period = find_period(n, static_cast<unsigned long>(root));
            if (period % 2 == 1) {
                ++num_fractions_with_odd_period;
            }
        }
    }

    return num_fractions_with_odd_period;
}
