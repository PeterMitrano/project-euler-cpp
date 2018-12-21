#pragma once

#include <cstdlib>

constexpr unsigned long long integer_sqrt(unsigned long long const n) {
    double xk = n;
    double xk_ = xk;
    while (true) {
        xk_ = 1.0 / 2 * (xk + n / xk);
        if (xk - xk_ < 1) {
            break;
        }
        xk = xk_;
    }
    return xk;
}
