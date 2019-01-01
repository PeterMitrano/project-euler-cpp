#include <sstream>
#include <fmt/format.h>
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

unsigned long problem() {
    std::ifstream fs("../p099_base_exp.txt");
    if (!fs.good()) {
        return 0ul;
    }

    std::string line;
    auto max_x{0.0};
    auto i{1ul};
    auto max_i{0ul};
    while (fs >> line) {
        auto base{0u};
        auto exp{0u};
        std::stringstream ss(line);
        ss >> base;
        ss.ignore();
        ss >> exp;
        auto const x = exp * std::log(base);
        if (x  > max_x) {
            max_x = x;
            max_i = i;
        }
        ++i;
    }

    return max_i;
}