#include <iostream>

#include <common/palandrome.h>

unsigned long problem() {
    auto largest_palandrome{0ul};
    for (auto a = 100u; a < 1000u; ++a) {
        for (auto b = a; b < 1000u; ++b) {
            auto const c = b * a;
            if (c > largest_palandrome and is_palandrome(c)) {
                largest_palandrome = c;
            }
        }

    }
    return largest_palandrome;
}
