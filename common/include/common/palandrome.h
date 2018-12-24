#pragma once

#include <common/digiterator.h>

using namespace std;

auto is_palandrome(unsigned long N) {
    Digiterator digits(N);
    auto front = digits.begin();
    auto back = digits.rbegin();
    for (auto i = 0u; i < digits.size() / 2; ++i) {
        if (*front != *back) {
            return false;
        }
        ++front;
        ++back;
    }
    return true;
}

