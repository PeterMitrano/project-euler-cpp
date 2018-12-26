#include <common/big_integer.h>

template <typename T>
struct Fraction {
    explicit Fraction(T i) : n(i), d(1) {}

    explicit Fraction(T n, T d) : n(n), d(d) {}

    T n{0};
    T d{1};

};
