#include <functional>
#include <common/fraction.h>

auto e_sequence(unsigned long k) {
    if (k == 0u) {
        return BigInteger{2};
    } else if (k % 3 == 2) {
        return BigInteger{(k + 1) * 2 / 3};
    } else {
        return BigInteger{1};
    }
};

template <typename T>
auto kth_convergent_fraction(unsigned long const k, std::function<T(unsigned long)> a_sequence) {
    T last_n{a_sequence(k)};
    T n{a_sequence(k - 1) * a_sequence(k) + T{1}};

    for (auto i{2ul}; i <= k; i++) {
        auto const temp = n;
        n = a_sequence(k - i) * n + last_n;
        last_n = temp;
    }

    return Fraction<T>{n, last_n};
}
