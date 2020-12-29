#include <vector>
#include <utility>
#include <cmath>
#include <deque>
#include <iostream>
#include <fstream>
#include <string>

#include <common/enumerate.h>
#include <common/big_integer.h>

using Solution = std::vector<int>;

auto ctoi(auto c)
{
    return static_cast<int>(c - '0');
};

void print_solution(Solution const &solution)
{
    for (auto const &d : solution)
    {
        std::cout << d;
    }
    std::cout << '\n';
};

void print_entries(std::vector<std::deque<int>> const &entries)
{
    std::cout << "---\n";
    for (auto const &e : entries)
    {
        for (auto const &j : e)
        {
            std::cout << j << ",";
        }
        std::cout << '\n';
    }
};

BigInteger vector_of_digits_to_int(auto v)
{
    BigInteger v_as_int{0};
    for (auto[i, digit] : enumerate(v))
    {
        BigInteger exponent(1);
        for (auto j = 0ul; j < v.size() - i - 1; ++j)
        {
            exponent = exponent * BigInteger(10);
        }
        v_as_int += BigInteger(digit) * exponent;
    }
    return v_as_int;
};

std::pair<bool, Solution>
search_recursive(std::vector<std::deque<int>> entries,
                 Solution solution,
                 Solution &best_solution,
                 std::vector<Solution> &solutions)
{
    auto all_queues_empty = true;
    for (auto d = 0; d <= 9; ++d)
    {
        // see if we can pop "d" from the front of the queues
        auto working_entries = entries;
        auto no_entries_start_with_d = true;
        for (auto &working_entry : working_entries)
        {
            if ((not working_entry.empty()) and working_entry.front() == d)
            {
                no_entries_start_with_d = false;
                all_queues_empty = false;
                working_entry.pop_front();
            }
        }

        if (solution.size() > best_solution.size())
        {
            break;
        }

        if (not no_entries_start_with_d)
        {
            auto new_solution = solution;
            new_solution.push_back(d);
            // print_entries(working_entries);
            auto result = search_recursive(working_entries, new_solution, best_solution, solutions);
            auto const solved = result.first;
            if (solved)
            {
                new_solution = result.second;
                auto const &new_solution_int = vector_of_digits_to_int(new_solution);
                auto const &best_solution_int = vector_of_digits_to_int(best_solution);
                if (new_solution_int < best_solution_int)
                {
                    print_solution(new_solution);
                    best_solution = new_solution;
                }
                solutions.push_back(result.second);
            }
        }
    }
    if (all_queues_empty)
    {
        solutions.push_back(solution);
        return {true, solution};
    }
    return {false, solution};
};

unsigned long problem()
{
    // read the file
    std::ifstream keylog;
    keylog.open("p079_keylog.txt");
    std::string line;
    std::vector<std::deque<int>> entries;
    while (getline(keylog, line))
    {
        std::deque<int> entry{ctoi(line[0]), ctoi(line[1]), ctoi(line[2])};
        entries.push_back(entry);
    }

    // over digits in the solution
    std::vector<Solution> solutions;
    Solution best_solution{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    auto const[solved, solution] = search_recursive(entries, Solution{}, best_solution, solutions);

    auto const solution_int = vector_of_digits_to_int(solution);
    std::cout << "Solution:" << solution_int.getNumber();
    return 0;
}