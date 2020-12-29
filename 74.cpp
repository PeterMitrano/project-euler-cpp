#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <numeric>

#include <common/digiterator.h>
#include <common/enumerate.h>

auto static factorial = [](auto n)
{
    switch (n)
    {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 24;
        case 5:
            return 120;
        case 6:
            return 720;
        case 7:
            return 5040;
        case 8:
            return 40320;
        case 9:
            return 362880;
        default:
            throw std::runtime_error("only 0-9");
    }
};

auto static sum_of_factorials = [](auto n)
{
    Digiterator digits(n);
    std::vector<int> factorials;
    std::ranges::transform(digits, std::back_inserter(factorials), factorial);
    return std::accumulate(factorials.cbegin(), factorials.cend(), 0u);
};

unsigned long problem()
{
    std::unordered_map<int, int> chain_lengths;
    auto compute_chain_length = [&](int n)
    {
        auto n_j = n;
        auto c = 0;
        auto min_c = 0;
        std::vector<int> mylist;
        while (true)
        {
            auto const it = std::find(mylist.cbegin(), mylist.cend(), n_j);
            if (it != mylist.cend())
            {
                min_c = std::distance(it, mylist.cend());
                c = 0;
                break;
            } else if (chain_lengths.contains(n_j))
            {
                c = chain_lengths[n_j];
                break;
            } else
            {
                mylist.push_back(n_j);
                n_j = sum_of_factorials(n_j);
            }
        }

        std::reverse(mylist.begin(), mylist.end());
        for (auto[j, n_j] : enumerate(mylist))
        {
            auto const chain_length = std::max(c + j + 1, static_cast<unsigned long>(min_c));
            chain_lengths[n_j] = chain_length;
//            std::cout << "adding " << n_j << " " << chain_length << '\n';
        }
        auto const chain_length = chain_lengths.at(n);
        return chain_length;
    };

    auto n_chains = 0;
    for (auto n = 1; n < 1'000'000; ++n)
    {
        auto const chain_length = compute_chain_length(n);
        if (chain_length == 60)
        {
            n_chains += 1;
        }
    }
    return n_chains;
}