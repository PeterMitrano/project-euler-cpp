import itertools


def phi(A: set, B: set, i: int, j: int):
    return (i in A and j in B) or (i in B and j in A)


def satisfies_constraints(A, B):
    return phi(A, B, 0, 1) and \
           phi(A, B, 0, 4) and \
           (phi(A, B, 0, 6) or phi(A, B, 0, 9)) and \
           (phi(A, B, 1, 6) or phi(A, B, 1, 9)) and \
           phi(A, B, 2, 5) and \
           (phi(A, B, 3, 6) or phi(A, B, 3, 9)) and \
           (phi(A, B, 4, 6) or phi(A, B, 4, 9)) and \
           phi(A, B, 8, 1)


def main():
    count = 0
    solutions = set()
    n = 10
    f = 6
    for A in itertools.combinations(range(n), f):
        for B in itertools.combinations(range(n), f):
            if satisfies_constraints(A, B):
                # make sure we haven't already found the same thing with "A" and "B" swapped
                if B + A not in solutions:
                    print(A, B)
                    solutions.add(A + B)
                    count += 1
    return count


if __name__ == '__main__':
    print(main())
