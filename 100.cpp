#include <iostream>

#include <common/sqrt.h>
#include <common/constants.h>

unsigned long problem() {
    auto u{1ul};
    auto v{1ul};
    auto T{0ul};
    while (T < pow10[12]) {
        auto temp = v;
        v = v + 2 * u;
        u = temp + u;
        T = (v+1)/2;
    }

    auto const B = (u + 1) / 2;
    return B;
}