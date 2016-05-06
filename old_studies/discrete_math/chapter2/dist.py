from itertools import permutations

a = [1, 2, 3, 4, 5]

permutate = [str(elem) for elem in permutations(a)]
permutate = sorted(permutate)

print(permutate)
