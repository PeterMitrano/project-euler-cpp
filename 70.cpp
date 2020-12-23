#include <iostream>

#include <common/sqrt.h>
#include <common/digiterator.h>

auto compute_phi(unsigned long n)
{
    auto n_j = n;
    auto phi_n = static_cast<double>(n);
    auto p = 2ul;
    outer_loop:
    for (p = 2ul; p <= integer_sqrt(n_j); ++p)
    {
        if (n_j % p == 0)
        {
            n_j = n_j / p;
            phi_n *= (1.0 - 1.0 / static_cast<double>(p));
            goto outer_loop;
        }
    }
    phi_n *= (1.0 - 1.0 / static_cast<double>(n_j));
    return static_cast<unsigned long long >(phi_n);
}

unsigned long problem()
{
    auto minimum_ratio{10.0};
    auto minimum_n{0ul};
    for (auto n{2ul}; n <= 10'000'000; ++n)
    {
        auto const phi_of_n = compute_phi(n);
        Digiterator digits_of_n(n);
        Digiterator digits_of_phi(phi_of_n);
        auto const is_perm = std::is_permutation(digits_of_n.cbegin(), digits_of_n.cend(), digits_of_phi.cbegin());
        if (is_perm and digits_of_n.size() == digits_of_phi.size())
        {
            auto const ratio = static_cast<double>(n) / phi_of_n;
            if (ratio < minimum_ratio)
            {
                minimum_ratio = ratio;
                minimum_n = n;
            }
        }
    }
    return minimum_n;
}