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
