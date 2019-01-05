#include <iostream>
#include <chrono>
#include <fmt/format.h>
#include "cxxopts.hpp"

using namespace std;

unsigned long problem();

int main(int argc, char **argv) {
    cxxopts::Options parser{"euler_runner", "Run, and optionally time, a solution to a Project Euler problem"};
    parser.add_options()
            ("t,time", "time the solution")
            ("p,porcelain", "output just the mean runtime in nanoseconds")
            ("n,iterations", "maximum iterations to run", cxxopts::value<unsigned int>()->default_value("1000"));
    auto const args = parser.parse(argc, argv);
    auto const time = args["time"].as<bool>();
    auto const porcelain = args["porcelain"].as<bool>();
    auto const iters = args["iterations"].as<unsigned int>();

    if (time or porcelain) {
        auto const t0 = chrono::high_resolution_clock::now();
        chrono::duration<double> dt = chrono::system_clock::now() - t0;
        auto i = 0u;
        unsigned long result{0ul};
        for (; dt <= 60s and i < iters; ++i) {
            result = problem();
            dt = chrono::system_clock::now() - t0;
        }

        auto const ns = chrono::duration_cast<chrono::nanoseconds>(dt).count();
        auto const us = chrono::duration_cast<chrono::microseconds>(dt).count();
        auto const ms = chrono::duration_cast<chrono::milliseconds>(dt).count();
        auto const s = chrono::duration_cast<chrono::seconds>(dt).count();

        if (porcelain) {
            std::cout << ns / i << '\n';
        } else {
            std::cout << fmt::format("Result: {}\n", result);
            std::cout << fmt::format("Iterations: {}\n", i);
            std::cout << fmt::format("Total Seconds: {}\n", dt.count());
            auto const seconds_per = dt.count() / i;
            if (seconds_per < 1e-6) {
                std::cout << fmt::format("Nanoseconds Per Solve: {}\n", ns / i);
            } else if (seconds_per < 1e-3) {
                std::cout << fmt::format("Microseconds Per Solve: {}\n", us / i);
            } else if (seconds_per < 1) {
                std::cout << fmt::format("Milliseconds Per Solve: {}\n", ms / i);
            } else {
                std::cout << fmt::format("Seconds Per Solve: {}\n", s / i);
            }
        }
    } else {
        std::cout << problem() << '\n';
    }
    return 0;
}