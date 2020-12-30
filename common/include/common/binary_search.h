#pragma once

tempalate<typename T>
binary_search(T lower, T upper, std::function<bool(T)> condition)
{
    T t;
    while (true)
    {
        TODO!!!
        if (condition(t))
        {
            return t;
        }
    }
}