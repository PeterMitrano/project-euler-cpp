#include <common/pow.h>
#include <unordered_set>
#include <iostream>
#include <common/sieve.h>

auto const primes = primes_list<10000>();

unsigned long problem()
{
    // FIXME: this counts duplicates, because 4^2 + 3^3 + 2^4 is the same as ^2 + 3^3 + 2^4
    constexpr auto const m = 50'000'000;
    std::unordered_set<unsigned int> zs;
    unsigned int a_idx;
    unsigned int b_idx;
    auto c_idx = 0u;
    while (true)
    {
        b_idx = 0;
        while (true)
        {
            a_idx = 0;
            while (true)
            {
                auto const prime_a = primes[a_idx];
                auto const prime_b = primes[b_idx];
                auto const prime_c = primes[c_idx];
                auto const z = ipow(prime_a, 2) + ipow(prime_b, 3) + ipow(prime_c, 4);
                if (z < m)
                {
                    // std::cout << prime_a << "^2 + " << prime_b << "^3 + " << prime_c << "^4\n";
                    zs.emplace(z);
                } else
                {
                    break;
                }
                ++a_idx;
            }
            if (a_idx == 0)
            {
                break;
            }
            ++b_idx;
        }
        if (b_idx == 0)
        {
            break;
        }
        ++c_idx;
    }
    return zs.size();
}
