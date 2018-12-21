#include <iostream>

constexpr auto problem_002() {
    auto sum{2};
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

int main() {
    std::cout << problem_002() << '\n';
    return 0;
}
