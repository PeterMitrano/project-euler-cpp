#include <iostream>

unsigned long problem() {
    auto answer{0ul};
    for (auto i = 0; i < 1000; ++i) {
        if (i % 3 == 0 or i % 5 == 0) {
            answer += i;
        }
    }

    return answer;
}
