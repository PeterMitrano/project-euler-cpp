#include <fmt/format.h>
#include <cmath>
#include <iostream>
#include <common/fabs.h>
#include <common/digiterator.h>
#include <common/big_integer.h>
#include <numeric>

auto a_sequence(unsigned long k) {
    if (k == 0u) {
        return BigInteger{2};
    } else if (k % 3 == 2) {
        return BigInteger{(k + 1) * 2 / 3};
    } else {
        return BigInteger{1};
    }
};

auto numerator_of_convergence_level(unsigned long const convergence_level) {
    BigInteger last_n{a_sequence(convergence_level)};
    BigInteger n{a_sequence(convergence_level - 1) * a_sequence(convergence_level) + BigInteger{1}};
    for (auto i{2ul}; i <= convergence_level; i++) {
        auto const temp = n;
        n = a_sequence(convergence_level - i) * n + last_n;
        last_n = temp;
    }

    return n;
}

unsigned long problem() {
    constexpr auto const N = 100u;
    auto const numerator = numerator_of_convergence_level(N - 1);
    std::cout << numerator.getNumber() << '\n';
    auto sum{0u};
    for (auto const &digit_char : numerator.getNumber()) {
       auto digit{static_cast<unsigned int>(digit_char - '0')};
       sum += digit;
    }
    return sum;
}
