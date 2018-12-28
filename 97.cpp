#include <common/pow.h>
#include <common/pow.h>

unsigned long problem() {
    constexpr auto const exponent{7830457u};
    constexpr auto first_exponent{exponent % 29};
    auto result{pow2(first_exponent)};
    for (auto i{0u}; i < exponent / 29; ++i) {
        result = (result * pow2(29)) % pow10[10];
    }

    result = (28433 * result + 1) % pow10[10];

    return result;
}