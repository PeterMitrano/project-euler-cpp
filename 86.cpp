#include <iostream>
#include <functional>
#include <cmath>

bool check_shortest_path_integral(unsigned int h, unsigned int w, unsigned int d)
{
    auto const z = (h + w) * (h + w) + d * d;
    auto const s = static_cast<unsigned int>(std::sqrt(z)) * static_cast<unsigned int>(std::sqrt(z));
    return s == z;
}

unsigned int count_integral_paths(unsigned int const m)
{
    auto n_integral = 0u;
    for (auto h = 1u; h <= m; ++h)
    {
        for (auto w = h; w <= m; ++w)
        {
            for (auto d = w; d <= m; ++d)
            {
                auto const is_integral = check_shortest_path_integral(h, w, d);
                if (is_integral)
                {
                    ++n_integral;
                }
            }
        }
    }
    return n_integral;
}

auto find_upper_bound(auto const start, auto condition)
{
    // double until condition is true
    auto upper = start;
    auto lower = start;
    while (true)
    {
        if (condition(upper))
        {
            return std::pair{lower, upper};
        }
        lower = upper;
        upper *= 2;
    }
}

unsigned long find_first_where(unsigned int start, auto condition)
{
    auto[lower, upper] = find_upper_bound(start, condition);
    // binary search for the lowest number for which condition is true
    while (upper > lower + 1)
    {
        auto const m = (upper + lower) / 2;
        if (condition(m))
        {
            upper = m;
        } else
        {
            lower = m;
        }
    }
    return upper;
}

unsigned long problem()
{
    auto condition = [](auto const m)
    {
        auto const n_integral = count_integral_paths(m);
        return n_integral >= 1'000'000;
    };

    auto lower = 100u;
    return find_first_where(lower, condition);
}