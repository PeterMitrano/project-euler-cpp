#include <iostream>

unsigned long partition(unsigned long n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }
    auto sum{0ul};
    auto pentagonal = [](int k) {
        return static_cast<unsigned long>(k * (3 * k - 1) / 2);
    };
    auto k{1};
    while (true) {
        auto const sign = k % 2 == 0 ? -1 : 1;
        auto const pent = pentagonal(k);
        if (n < pent) {
            break;
        }
        sum += sign * partition(n - pent);
        if (k > 0) {
            k = -k;
        } else {
            k = -k + 1;
        }
    }
    return sum;
}

unsigned long problem() {
    auto n{0ul};
    while (true) {
        auto const p = partition(n);
        std::cout << n << " " << p << '\n';
        ++n;
        if (p > 1'000'000ul) {
            break;
        }
    }

    return 0ul;
}