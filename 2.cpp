#include <iostream>

unsigned long problem() {
    auto sum{2ul};
    auto last_fib = 1;
    auto fib = 2;
    while (fib < 4'000'000) {
        auto const temp = fib;
        fib = fib + last_fib;
        if (fib % 2 == 0) {
            sum += fib;
        }
        last_fib = temp;
    }

    return sum;
}

