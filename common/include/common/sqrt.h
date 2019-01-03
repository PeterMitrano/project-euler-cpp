#pragma once

#include <cstdlib>

constexpr unsigned long integer_sqrt(unsigned long n) {
    unsigned long op = n;
    unsigned long res = 0;
    // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for unsigned long type
    unsigned long one = 1uL << 30;


    // "one" starts at the highest power of four <= than the argument.
    while (one > op) {
        one >>= 2;
    }

    while (one != 0) {
        if (op >= res + one) {
            op = op - (res + one);
            res = res + 2 * one;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}
