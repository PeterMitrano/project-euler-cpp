#include <iostream>
#include <numeric>
#include <vector>
#include <common/ctoi.h>
#include <common/big_integer.h>
#include <common/digiterator.h>
#include <cmath>

auto append_digit(BigInteger const &bigint, unsigned int const d)
{
    return BigInteger(bigint.getNumber() + std::to_string(d));
}

auto sum_of_sqrt_digits(auto n)
{
    auto const int_sqrt = static_cast<unsigned int>(std::floor(std::sqrt(n)));
    auto const int_sqrt_n_digits = static_cast<unsigned int>(log10(int_sqrt));
    BigInteger digits(int_sqrt);
    if (int_sqrt * int_sqrt == n)
    {
        return 0u;
    }
    while (true)
    {
        auto d = 0u;
        for (; d < 10; ++d)
        {
            auto const test_digits = append_digit(digits, d);
            auto const n_approx = test_digits * test_digits;
            auto const n_approx_no_decimals = ???;
            auto const n_approx_int = std::stoul(n_approx_no_decimals);
            if (n_approx_int >= n)
            {
                break;
            }
        }
        // add up the digits including d - 1
        d -= 1;
        digits = append_digit(digits, d);
        if (digits.getDigits() == 100)
        {
            break;
        }
    }
    std::vector<unsigned int> digits_vec;
    auto ctoi_ = [](auto c) { return ctoi(c); };
    std::transform(digits.getNumber().cbegin(), digits.getNumber().cend(), std::back_inserter(digits_vec), ctoi_);
    auto const sum_of_digits = std::accumulate(digits_vec.cbegin(), digits_vec.cend(), 0u);
    return sum_of_digits;
}

unsigned long problem()
{
    auto x = sum_of_sqrt_digits(10u);
    std::cout << x << '\n';
    return 0ul;
    auto total_sum = 0u;
    for (auto n = 2u; n < 100u; ++n)
    {
        // build up the sqrt of n digit by digit
        auto sum_of_decimal_digits = sum_of_sqrt_digits(n);
        total_sum += sum_of_decimal_digits;
    }

    return total_sum;
}