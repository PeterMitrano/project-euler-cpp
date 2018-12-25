#include <common/sieve.h>
#include <common/sqrt.h>
#include <iostream>

constexpr bool is_prime(unsigned long p) {
    for (auto divisor{2ul}; divisor <= integer_sqrt(p); ++divisor) {
        if (p % divisor == 0) {
            return false;
        }
    }
    return true;
}

unsigned long problem() {
    auto p{3ul}, idx{1ul};
    while (true) {
        if (is_prime(p)) {
            ++idx;
            if (idx == 10'001) {
                return p;
            }
        }
        p += 2;
    }
}