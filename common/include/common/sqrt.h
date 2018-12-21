#pragma once

#include <cstdlib>

constexpr auto integer_sqrt(long int const n) {
    auto xk = n;
    auto xk_ = xk;
    while (true) {
        xk_ = 1 / 2 * (xk + n / xk);
        if (xk - xk_ >= 1) {
            break;
        }
        xk = xk_;
    }
    return xk;
}
