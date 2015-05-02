def binomial(n, k):
    '''
     given n items, how many ways to select k items
     this is a counting problem, hence recursive solution
     binomial(n,k) = n!/(k!*(n-k)!)
     Notes :
     1. division must be done at the end.
     2. Using python's '//' operator that will throw away
        remainders.
    '''
    if k == 0:
        return 1
    return n * binomial(n - 1, k - 1) // k


def binomial_iter(n, k):
    lmul = 1
    rdiv = 1
    while k > 0:
        (n, k, lmul, rdiv) = (n - 1, k - 1, n * lmul, k * rdiv)
    return lmul // rdiv


def binomial_iter2(n, k):
    '''
        By definition
        binomial(n,k) == n!/(k!(n-k)!)

        the loop below calculating something different.
        It calculates (n!/(n-k)!) together.
        binomial(n,k) = (n!/(n-k)!)/k!
    '''

    lmul = rdiv = 1
    while k > 0:
        (n, k, lmul, rdiv) = (n - 1, k - 1, n * lmul, k * rdiv)
    return lmul // rdiv


def binomial_iter3(n, k):
    if k > (n - k):
        k = n - k
    t = k
    (n, prev_x) = (n - k + 1, 1)
    for k in range(1, t + 1):
        (n, prev_x) = (n + 1, n * prev_x // k)
    return prev_x


def bino(n, k):
    if k > (n - k):
        k = n - k

    (n,  prev_x) = (n - k + 1,  1)
    for k in range(1, k + 1):
        (n, prev_x) = (n + 1, n * prev_x // k)  # b(n,k) = n/k*b(n-k,k-1)
    return prev_x

assert bino(100, 3) == binomial_iter3(100, 3)
print(bino(100, 3))
print(binomial(100, 3))
