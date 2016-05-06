# from itertools import compress
from itertools import count
import matplotlib.pyplot as plt
import time

'''
 find primes by the sieves
 Rules:
    (1). Any composite number less than p**2 is sifted by
         a prime less than p**2
    (2). When sifting by p, start marking at p**2
    (3). If we want to sift up to M, stop sifting when p**2 > m

 Formulars:
    [1] value at index: value(index) = 2*index+3
    [2] index at value: index(value) = (value-3)/2
    [3] index(value(i)**2) = 2i**2 + 6i +3:
        Explaination: Square the prime, and find the index of the square of
                    that prime.
'''


def mark_sieve(bool_array, start, end, factor, counter):
    while start < end:
        if bool_array[start] is True:
            next(counter)

        bool_array[start] = False
        start += factor


def sift(n):
    # sieve = [num for num in range(3, n + 1) if (num % 2) != 0]
    end_index = (n - 2) // 2
    array = [True] * end_index

    i = 0
    index_of_square = 3
    factor = 3
    c = count(start=-1)
    while(index_of_square < n):
        if array[i]:
            # By Rule (2), value(i) is prime, start marking @ value(i)**2
            # By Formular [3], we calculate the index_of_square
            mark_sieve(array, index_of_square, end_index, factor, c)
        i += 1
        index_of_square += factor
        factor += 2
        index_of_square += factor
    return end_index - next(c)

# t_0 = time.time()
# print(sift(10**5))
# print('time elapsed', time.time() - t_0)

xaxis = [10**i for i in range(1, 3)]
t_0 = time.time()
yaxis = [sift(n) for n in xaxis]
print('time elapsed', time.time() - t_0)
print(list(zip(xaxis, yaxis)))
plt.plot(xaxis, yaxis)
plt.show()
