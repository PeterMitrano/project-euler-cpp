#pragma once

#include <common/constants.h>

constexpr unsigned long pow2(unsigned long exponent) {
    return 1ul << exponent;
}

constexpr unsigned long ipow(unsigned long base, unsigned long exponent) {
    unsigned long i = 1;
    for (unsigned long j = 1; j <= exponent; j++)  i *= base;
    return i;
}
