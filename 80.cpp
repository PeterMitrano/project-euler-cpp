#include <iostream>
#include <numeric>
#include <vector>
#include <common/ctoi.h>
#include <common/big_integer.h>
#include <common/digiterator.h>
#include <cmath>

#define result auto const

auto append_digit(BigInteger const &bigint, unsigned int const d)
{
    return BigInteger(bigint.getNumber() + std::to_string(d));
}

auto sum_of_sqrt_digits(auto n)
{
    result int_sqrt = static_cast<unsigned int>(std::floor(std::sqrt(n)));
    BigInteger sqrt_approx(int_sqrt);
    if (int_sqrt * int_sqrt == n)
    {
        return 0u;
    }
    auto decimal_digits = 0u;
    while (true)
    {
        auto d = 0u;
        for (; d < 10; ++d)
        {
            result test_digits = append_digit(sqrt_approx, d);
            result n_approx = test_digits * test_digits;
            result n_approx_decimal_digits = (decimal_digits + 1) * 2;
            result n_approx_int_digits = n_approx.getDigits() - n_approx_decimal_digits;
            result n_approx_int = std::stoul(n_approx.getNumber().substr(0, n_approx_int_digits));
            if (n_approx_int >= n)
            {
                break;
            }
        }
        // add up the sqrt_approx including d - 1
        d -= 1;
        ++decimal_digits;
        sqrt_approx = append_digit(sqrt_approx, d);
        if (sqrt_approx.getDigits() == 100)
        {
            break;
        }
    }
    std::vector<unsigned int> digits_vec;
    auto ctoi_ = [](auto c) { return ctoi(c); };
    std::transform(sqrt_approx.getNumber().cbegin(), sqrt_approx.getNumber().cend(), std::back_inserter(digits_vec), ctoi_);
    result sum_of_digits = std::accumulate(digits_vec.cbegin(), digits_vec.cend(), 0u);
    return sum_of_digits;
}

unsigned long problem()
{
//    auto x = sum_of_sqrt_digits(10u);
//    std::cout << x << '\n';
//    return 0ul;
    auto total_sum = 0u;
    for (auto n = 2u; n < 100u; ++n)
    {
        // build up the sqrt of n digit by digit
        auto sum_of_decimal_digits = sum_of_sqrt_digits(n);
        total_sum += sum_of_decimal_digits;
    }

    return total_sum;
}