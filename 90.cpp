#include <unordered_set>
#include <iostream>
#include <vector>
#include <common/enumerate.h>
#include <common/constants.h>

using Set = std::unordered_set<int>;
using Solution = std::vector<int>;

namespace std
{

    template<>
    struct hash<Solution>
    {
        std::size_t operator()(const Solution &s) const
        {
            std::size_t hash = 0;
            for (auto const &[i, x] : enumerate(s))
            {
                hash += pow10[i] * x;
            }
            return hash;
        }
    };
}


[[nodiscard]] bool phi(Set const &A, Set const &B, int const i, int const j)
{
    return (A.contains(i) and B.contains(j)) or (B.contains(i) and A.contains(j));
}

[[nodiscard]] bool satisfies_constraints(Set const &A, Set const &B)
{
    return phi(A, B, 0, 1) and \
           phi(A, B, 0, 4) and \
           (phi(A, B, 0, 6) or phi(A, B, 0, 9)) and \
           (phi(A, B, 1, 6) or phi(A, B, 1, 9)) and \
           phi(A, B, 2, 5) and \
           (phi(A, B, 3, 6) or phi(A, B, 3, 9)) and \
           (phi(A, B, 4, 6) or phi(A, B, 4, 9)) and \
           phi(A, B, 8, 1);
}

struct RangeCombinations
{
    std::vector<bool> v;
    int n;

    RangeCombinations(int const n, int const r) : v(n), n(n)
    {
        std::fill(v.begin(), v.begin() + r, true);
    }

    bool advance_and_check_if_done()
    {
        return std::prev_permutation(v.begin(), v.end());
    }

    auto get()
    {
        Set combination;
        for (int i = 0; i < n; ++i)
        {
            if (v[i])
            {
                combination.emplace(i);
            }
        }
        return combination;
    }
};

std::vector<int> concat(Set const &a, Set const &b)
{
    std::vector<int> vector_a(a.begin(), a.end());
    std::vector<int> vector_b(b.begin(), b.end());
    vector_a.insert(vector_a.end(), vector_b.begin(), vector_b.end());
    return vector_a;
}

[[nodiscard]] unsigned long problem()
{
    auto count = 0;
    std::unordered_set<Solution> solutions;
    constexpr auto const n = 10;
    constexpr auto const r = 6;
    RangeCombinations range_combinations_a(n, r);
    RangeCombinations range_combinations_b(n, r);
    do
    {
        auto const &A = range_combinations_a.get();
        do
        {
            auto const &B = range_combinations_b.get();
            if (satisfies_constraints(A, B))
            {
                // make sure we haven't already found the same thing with "A" and "B" swapped
                if (not solutions.contains(concat(B, A)))
                {
                    auto const solution = concat(A, B);
                    solutions.emplace(solution);
                    count += 1;
                }
            }
        } while (range_combinations_b.advance_and_check_if_done());
    } while (range_combinations_a.advance_and_check_if_done());
    return count;
}
