def binary(n):
    bin = ''
    while n > 0:
        if n % 2 == 0:
            bin = '0' + bin
        else:
            bin = '1' + bin
        n >>= 1
    return bin

print(binary(32343))
print('{0:10b}'.format(32343))

print(binary(5632343532))

this is a new way to do this
may be may be not can you notice any diff?
