import doctest


def factorial(*args, **kwds):
    '''
     >>> [factorial(i) for i in range(1,10)]
     [1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    '''
    def call(f):
        """Instruct trampoline to call f with the args that follow."""
        def g(*args, **kwds):
            return (f, args, kwds)
        return g

    def result(value):
        """Instruct trampoline to stop iterating and return a value."""
        return None, value, None

    def trampoline(n, acc=1):
        if n < 2:
            return result(acc)

        g = call(trampoline)

        # returning the tuple (trampoline, n, n*acc)
        return g(n - 1, n * acc)

    f = trampoline
    # the trampoline
    while f is not None:
        (f, args, kwds) = f(*args, **kwds)
        # print('in factorial ', h, trampoline)
    return args


if __name__ == '__main__':
    doctest.testmod()
