#include <iostream>

#include <common/palandrome.h>

auto problem_004() {
    auto largest_palandrome{0u};
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

int main() {
    std::cout << problem_004() << '\n';
    return 0;
}
