#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

unsigned long problem() {
    std::vector<unsigned int> digits{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<unsigned int> result;

    while (std::next_permutation(digits.begin(), digits.end())) {
        {
            auto const a = digits[0] + digits[4] + digits[5];
            auto const b = 10 + digits[5] + digits[6];
            auto const c = digits[1] + digits[6] + digits[7];
            auto const d = digits[2] + digits[7] + digits[8];
            auto const e = digits[3] + digits[8] + digits[4];
            if (a == b and b == c and c == d and d == e
                and digits[0] < digits[1]
                and digits[0] < digits[2]
                and digits[0] < digits[3]) {
                result = {digits[0], digits[4], digits[5],
                          10, digits[5], digits[6],
                          digits[1], digits[6], digits[7],
                          digits[2], digits[7], digits[8],
                          digits[3], digits[8], digits[4]};
            }
        }
        {
            auto const a = digits[0] + digits[4] + digits[5];
            auto const b = digits[1] + digits[5] + digits[6];
            auto const c = 10 + digits[6] + digits[7];
            auto const d = digits[2] + digits[7] + digits[8];
            auto const e = digits[3] + digits[8] + digits[4];
            if (a == b and b == c and c == d and d == e
                and digits[0] < digits[1]
                and digits[0] < digits[2]
                and digits[0] < digits[3]) {
                result = {digits[0], digits[4], digits[5],
                          digits[1], digits[5], digits[6],
                          10, digits[6], digits[7],
                          digits[2], digits[7], digits[8],
                          digits[3], digits[8], digits[4]};
            }
        }
        {
            auto const a = digits[0] + digits[4] + digits[5];
            auto const b = digits[1] + digits[5] + digits[6];
            auto const c = digits[2] + digits[6] + digits[7];
            auto const d = 10 + digits[7] + digits[8];
            auto const e = digits[3] + digits[8] + digits[4];
            if (a == b and b == c and c == d and d == e
                and digits[0] < digits[1]
                and digits[0] < digits[2]
                and digits[0] < digits[3]) {
                result = {digits[0], digits[4], digits[5],
                          digits[1], digits[5], digits[6],
                          digits[2], digits[6], digits[7],
                          10, digits[7], digits[8],
                          digits[3], digits[8], digits[4]};
            }
        }
        {
            auto const a = digits[0] + digits[4] + digits[5];
            auto const b = digits[1] + digits[5] + digits[6];
            auto const c = digits[2] + digits[6] + digits[7];
            auto const d = digits[3] + digits[7] + digits[8];
            auto const e = 10 + digits[8] + digits[4];
            if (a == b and b == c and c == d and d == e
                and digits[0] < digits[1]
                and digits[0] < digits[2]
                and digits[0] < digits[3]) {
                result = {digits[0], digits[4], digits[5],
                          digits[1], digits[5], digits[6],
                          digits[2], digits[6], digits[7],
                          digits[3], digits[7], digits[8],
                          10, digits[8], digits[4]};
            }
        }
    }
    std::stringstream ss;
    for (auto i : result) {
        ss << i;
    }
    return std::strtoul(ss.str().c_str(), nullptr, 10);
}