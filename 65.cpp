#include <cmath>
#include <iostream>
#include <common/fabs.h>
#include <common/digiterator.h>
#include <common/convergent_fractions.h>
#include <numeric>

unsigned long problem() {
    constexpr auto const N = 100u;
    auto const fraction = kth_convergent_fraction<BigInteger>(N - 1, e_sequence);
    auto sum{0u};
    for (auto const &digit_char : fraction.n.getNumber()) {
       auto digit{static_cast<unsigned int>(digit_char - '0')};
       sum += digit;
    }
    return sum;
}
