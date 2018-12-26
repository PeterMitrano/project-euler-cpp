#include <common/big_integer.h>

auto e_sequence(unsigned long k) {
    if (k == 0u) {
        return BigInteger{2};
    } else if (k % 3 == 2) {
        return BigInteger{(k + 1) * 2 / 3};
    } else {
        return BigInteger{1};
    }
};

auto numerator_of_convergence_level(unsigned long const convergence_level, BigInteger(*a_sequence)(unsigned long)) {
    BigInteger last_n{a_sequence(convergence_level)};
    BigInteger n{a_sequence(convergence_level - 1) * a_sequence(convergence_level) + BigInteger{1}};
    for (auto i{2ul}; i <= convergence_level; i++) {
        auto const temp = n;
        n = a_sequence(convergence_level - i) * n + last_n;
        last_n = temp;
    }

    return n;
}
