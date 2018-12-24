#pragma once

#include <iterator>
#include <vector>

#include <common/constants.h>

constexpr auto num_digits(unsigned long v) {
    auto num_digits{1u};
    while (v >= 10) {
        v = v / 10;
        ++num_digits;
    }
    return num_digits;
}

class Digiterator {
public:
    using array_type = typename std::vector<unsigned int>;
    using iterator = typename array_type::iterator;
    using reverse_iterator = typename array_type::reverse_iterator;
    using const_iterator = typename array_type::const_iterator;
    using const_reverse_iterator = typename array_type::const_reverse_iterator;

private:
    const unsigned int size_;
    array_type digits;

public:

    explicit Digiterator(unsigned long N) : size_(num_digits(N)) {
        digits.resize(size_);
        for (auto i = 0u; i < size_; ++i) {
            digits[size_ - i - 1] = static_cast<unsigned int>(N / pow10[i] % 10u);
        }
    }

    unsigned long number() const {
        auto number{0ul};
        for (auto i = 0u; i < size_; ++i) {
            number += pow10[size_ - i - 1] * digits[i];
        }
        return number;
    }


    iterator begin() noexcept { return digits.begin(); }

    const_iterator cbegin() const noexcept { return digits.cbegin(); }

    iterator end() noexcept { return digits.end(); }

    const_iterator cend() const noexcept { return digits.cend(); }

    reverse_iterator rbegin() noexcept { return digits.rbegin(); }

    const_reverse_iterator rcbegin() const noexcept { return digits.crbegin(); }

    reverse_iterator rend() noexcept { return digits.rend(); }

    const_reverse_iterator rcend() const noexcept { return digits.crend(); }

    unsigned int operator[](unsigned int idx) const {
        return digits[idx];
    }

    unsigned int &operator[](unsigned int idx) {
        return digits[idx];
    }

    auto size() const {
        return size_;
    }
};

