import doctest


def factorial(n):
    if n < 2:
        return 1
    return n * factorial(n - 1)

# turn the previous function into tail recursion
# the key is to use an accummulator


def factorial_tailcal(n, acc=1):
    '''
        >>> factorial_tailcal(10)
        3628801
    '''
    while n > 1:
        (n, acc) = (n - 1, n * acc)
    return acc

if __name__ == "__main__":
    doctest.testmod()
