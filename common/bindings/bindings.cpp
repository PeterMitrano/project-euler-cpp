#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <common/sieve.h>

namespace py = pybind11;

constexpr std::size_t n_primes_py = 100'000;

auto prime_list_py()
{
    return primes_list<n_primes_py>();
}

PYBIND11_MODULE(euler_common_py, m)
{
    m.def("primes_list", prime_list_py, "get the primes below 100,000");
    m.attr("n_primes") = n_primes_py;
}