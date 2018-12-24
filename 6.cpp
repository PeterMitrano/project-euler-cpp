#include <utility>
#include <numeric>

unsigned long problem() {
    auto sum_of_squares = 0ul;
    auto sum = 0ul;
    for (auto i = 0; i <= 100; ++i) {
        sum_of_squares += i * i;
        sum += i;
    }
    auto const square_of_sums = sum * sum;
    return square_of_sums - sum_of_squares;
}