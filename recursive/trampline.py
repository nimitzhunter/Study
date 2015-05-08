import doctest


def factorial(*args, **kwds):
    '''
     >>> [factorial(i) for i in range(1,10)]
     [1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    '''
    def call(f):
        """
        Instruct trampoline to call f with the args that follow.

        THis procedure takes in a function and return a new function g()

        the function g return two main objects:
            1. the function that call() takes in as a variable
            2. all the objects taken in by g itself
        """
        def g(*args, **kwds):
            return (f, args, kwds)
        return g

    def result(value):
        """Instruct trampoline to stop iterating and return a value."""
        return None, value, None

    def trampoline(n, acc=1):
        """
        when trampoline is called, it is allocated on a stack frame.

            g = call(trampoline)

        On this line, we take the stack frame of trampoline and push it
        into function g().

        NOTE: g() always return the same stack frame that trampoline is located.
        """
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
