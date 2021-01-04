import math

import euler_common_py


def print_set(s: set):
    print(sorted(list(s)))


def create_prime_sets(prime_set: set, primes: list):
    # {2} {2,3} {2,5} {2,7} ... {2,99991} {2,3,5} {2,3,7} ... {2,3,99991} ... {2,3,5,7,11,13,17,19,23,29}
    new_primes = primes.copy()
    for p in primes:
        new_primes.remove(p)
        new_prime_set = prime_set.copy()
        new_prime_set.add(p)

        # now we test all the different powers of this set of primes
        product = math.prod(new_prime_set)
        if product < 1e10:
            # print_set(new_prime_set)
            create_prime_sets(new_prime_set, new_primes)
        else:
            return prime_set


def main():
    primes = euler_common_py.primes_list()
    from time import perf_counter
    t0 = perf_counter()
    create_prime_sets(set(), primes)
    print(perf_counter() - t0)


if __name__ == '__main__':
    main()
