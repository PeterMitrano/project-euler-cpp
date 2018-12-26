#include <cmath>
#include <iostream>
#include <common/convergent_fractions.h>
#include <utility>

unsigned long problem() {
    auto diophantine = [&](unsigned long n) {
        auto i{1u};
        auto m{0ul};
        auto d{1ul};
        auto a0{static_cast<unsigned long>(sqrt(n))};
        auto a{a0};
        std::vector<unsigned long> a_vec{a0};

        auto n_sequence = [&](unsigned long k) {
            return BigInteger{a_vec[k]};
        };

        while (true) {

            m = d * a - m;
            d = (n - m * m) / d;
            a = (a0 + m) / d;
            a_vec.push_back(a);

            auto const fraction = kth_convergent_fraction<BigInteger>(i, n_sequence);
            if ((fraction.n * fraction.n > BigInteger{n} * fraction.d * fraction.d) and
                (fraction.n * fraction.n - BigInteger{n} * fraction.d * fraction.d == BigInteger{1})) {
                return fraction;
            }

            ++i;
        }
    };

    constexpr auto const D{1000ul};
    BigInteger maximizing_x{0};
    auto maximizing_n{0ul};
    for (auto n{2ul}; n <= D; ++n) {
        if (std::rint(sqrt(n)) != sqrt(n)) {
            auto[x, y] = diophantine(n);
            if (x > maximizing_x) {
                maximizing_x = x;
                maximizing_n = n;
            }
        }
    }

    return maximizing_n;
}
