#include <iostream>

constexpr auto problem_001() {
    auto answer{0};
    for (auto i = 0; i < 1000; ++i) {
        if (i % 3 == 0 or i % 5 == 0) {
            answer += i;
        }
    }

    return answer;
}

int main() {
    std::cout << problem_001() << '\n';
    return 0;
}