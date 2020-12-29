#include <utility>

#pragma once

#include <iterator>
#include <vector>

#include <common/constants.h>

constexpr auto num_digits(unsigned long v)
{
    auto num_digits{1u};
    while (v >= 10)
    {
        v = v / 10;
        ++num_digits;
    }
    return num_digits;
}

class Digiterator
{
public:
    using array_type = typename std::vector<unsigned int>;
    using iterator = typename array_type::iterator;
    using reverse_iterator = typename array_type::reverse_iterator;
    using const_iterator = typename array_type::const_iterator;
    using const_reverse_iterator = typename array_type::const_reverse_iterator;

private:
    array_type digits;
    // -1 means at the end, aka all digits are to the left of the decimal
    // if it was 0, then all digits would be to the right of the decimal
    // if it was 1, then 1 digit would be to the right of the decimal, etc...
    int decimal_place = -1;

public:

    Digiterator() : digits()
    {}

    explicit Digiterator(array_type d) : digits(std::move(d))
    {}

    explicit Digiterator(unsigned long N)
    {
        auto const size = num_digits(N);
        digits.resize(size);
        for (auto i = 0u; i < size; ++i)
        {
            digits[size - i - 1] = static_cast<unsigned int>(N / pow10[i] % 10u);
        }
    }

    [[nodiscard]] unsigned long number() const
    {
        auto number{0ul};
        for (auto i = 0u; i < digits.size(); ++i)
        {
            // this is faster
            auto const pow10_idx = digits.size() - i - 1;
            if (pow10_idx >= pow10.size())
            {
                throw std::out_of_range("cannot convert digits to a number, it would be too large");
            }
            number += pow10[pow10_idx] * digits[i];
        }
        return number;
    }


    iterator begin() noexcept
    { return digits.begin(); }

    [[nodiscard]] const_iterator cbegin() const noexcept
    { return digits.cbegin(); }

    iterator end() noexcept
    { return digits.end(); }

    [[nodiscard]] const_iterator cend() const noexcept
    { return digits.cend(); }

    reverse_iterator rbegin() noexcept
    { return digits.rbegin(); }

    [[nodiscard]] const_reverse_iterator rcbegin() const noexcept
    { return digits.crbegin(); }

    reverse_iterator rend() noexcept
    { return digits.rend(); }

    [[nodiscard]] const_reverse_iterator rcend() const noexcept
    { return digits.crend(); }

    unsigned int operator[](unsigned int idx) const
    {
        return digits[idx];
    }

    unsigned int &operator[](unsigned int idx)
    {
        return digits[idx];
    }

    [[nodiscard]] auto size() const
    {
        return digits.size();
    }
};

