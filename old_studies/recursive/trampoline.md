# Trampoline Method for Recursion

Idea:during recursion, only allocate one stack frame and always recursively use that stack frame.


Overly complicated procedure to do something simple. In most situation, this can be done with a conversion to loop.

    def factorial(*args, **kwds):
        def call(f):
            def g(*args, **kwds):
                return f, args, kwds
            return g


        def result(value):
            return None, value, None

        def trampoline(n, acc=1):
            if n < 2:
                return result(acc)
            g = call(trampoline)
            tramp = g(n - 1, n * acc)
            return tramp

        h = trampoline
        # the trampoline
        while h is not None:
            h, args, kwds = h(*args, **kwds)
        return args


The function *call* takes in a function and return that function. The magic happens on line:

    def trampoline(n, acc=1):
        if n < 2:
            return result(acc)
        g = call(trampoline)
        tramp = g(n - 1, n * acc)
        return tramp
The first magic happens in the function trampoline. What every calling trampoline, the address of the function is stored and returned by function *call*. When being returned, all the work is being done by the accumulator *n\*acc*, instead of recursion.

    h, args, kwds = h(\*args, \*\*kwds)

Notice that *def g* return the function that *call* takes in. In  *h, args, kwds = h(\*args, \*\*kwds)*, *h* is the original function and not a new stack frame. No new stack frame is being allocated, just one stack frame keep being bounced back and forth like using a trampoline.

This method is called trampoline because the original allocated stack frame is always bounced back.
