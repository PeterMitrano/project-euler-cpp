#include <common/sieve.h>
#include <chrono>
#include <fmt/format.h>
#include <iostream>
#include <numeric>
#include <set>
#include <unordered_set>
#include <vector>

using Set = std::set<int>;
using Primes = std::vector<unsigned int>;

//constexpr auto M = 10'000'000'000;
constexpr auto M = 100'000'000;

void print_set(auto set)
{
    for (auto s : set)
    {
        std::cout << s << ", ";
    }
    std::cout << '\n';
}

unsigned int global_count = 0;

void create_prime_sets(Set const prime_set, Primes const primes, std::size_t index, unsigned long const product)
{
    for (auto i = index; i < primes.size(); ++i)
    {
        auto const p = primes[i];
        auto new_prime_set = prime_set;
        new_prime_set.emplace(p);

        auto const new_product = product * p;
        if (new_product < M)
        {
            print_set(new_prime_set);
//            global_count += 1;
            create_prime_sets(new_prime_set, primes, i + 1, new_product);
        } else
        {
            return;
        }
    }
}

unsigned long problem()
{
    // recursively generate all combinations of primes < 1e5 whose product is < 1e10
    // e.g. {2}, {2,5,31}, {3,613,1301}, etc ...

    // normally this would be a huge number, but since we can generate these in order, we can stop
    // generating early. For instance, there can never be more than 11 primes in such a set,
    // because the product of the first 11 primes is >1e10

    auto const primes = primes_list<100'000>();
    auto const t0 = std::chrono::high_resolution_clock::now();
    create_prime_sets({}, primes, 0u, 1ul);
    auto const now = std::chrono::high_resolution_clock::now();
    std::cout << (now - t0).count() / 1'000'000 << '\n';
    return global_count;

    // testing
//    auto c = 0;
//    for (auto i = 0ul; i < 10'000'000'000ul; ++i)
//    {
//        c += i % 123;
//        if (c > 100)
//        {
//            c = 0;
//        }
//    }
//    return c;
}