def mul(n, a):
    '''
     (n+1)*a = a*n + a
    '''
    if n == 1:
        return a
    return mul(n - 1, a) + a

# n*a = n//2*2*a
# if n//2 is even then n*a = half(n)*2*a=half(half(n))*2*2*a
# if n is odd, then half(n)=half(n-1), n*a = half(n-1)*2*a

'''
 if n is even n = n/2 + n/2
 => n*a = (n/2+n/2)*a = (n/2)*2*a [1]

 if n is odd n = (n-1)/2 +(n-1)/2 + 1  [2]
 => n*a = (n-1)/2*(2*a)+a

 with odd(n) => half(n) = half(n-1)
 => n*a = half(n)*2*a + a

 Example: 5*6
 n = 5
 a = 6
 odd(5) => (5-1)/2 +(5-1)/2 = 1 + 1 = 2
 By [2] => 5*6 = 2*2*6 + 6 = 4*6 +6
 5*6 = 2*12 + 6
     = 24 +6
     = 30
'''


def mul1(n, a):
    if n == 1:
        return a

    result = mul1(n // 2, a + a)

    if (n % 2) != 0:
        result += a

    return result


def mul2(n, a):
    if (n % 2) != 0:
        result = a
    else:
        result = 0

    while n > 1:
        n, a = n // 2, a + a
        # the last value n==1 is always odd, thus res += a is the last calc
        if (n % 2) != 0:
            result += a
    return result


def mul3(n, a):
    # notice that when half(n) is always even, we will save half
    # the operation for checking it first
    while (n % 2) == 0:
        n, a = n // 2, a + a

    if n == 1:
        return a

    # n is odd, but it's not 1
    result = a

    while n > 1:
        n, a = n // 2, a + a
        # the last value n==1 is always odd, thus res += a is the last calc
        if (n % 2) != 0:
            result += a
    return result
