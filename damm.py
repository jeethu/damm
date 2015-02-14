import math

MATRIX = (
    (0, 3, 1, 7, 5, 9, 8, 6, 4, 2),
    (7, 0, 9, 2, 1, 5, 4, 8, 6, 3),
    (4, 2, 0, 6, 8, 7, 1, 3, 5, 9),
    (1, 7, 5, 0, 9, 8, 3, 4, 2, 6),
    (6, 1, 2, 3, 0, 4, 5, 9, 7, 8),
    (3, 6, 7, 4, 2, 0, 9, 5, 8, 1),
    (5, 8, 6, 9, 7, 2, 0, 1, 3, 4),
    (8, 9, 4, 5, 3, 6, 2, 0, 1, 7),
    (9, 4, 3, 8, 6, 1, 7, 2, 0, 5),
    (2, 5, 8, 1, 4, 3, 6, 7, 9, 0)
)


def checksum(n):
    accum = 0
    if n < 10 and n >= 0:
        return MATRIX[accum][n]
    ndigits = int(math.floor(math.log10(n) + 1))
    k = 10 ** (ndigits - 1)
    for i in range(ndigits):
        digit = n / k
        accum = MATRIX[accum][digit]
        n -= digit * k
        k /= 10
    return accum


def encode(n):
    return (n * 10) + checksum(n)


def check(n):
    return (encode(n) % 10) == 0

if __name__ == '__main__':
    assert checksum(572) == 4
    assert encode(572) == 5724
    assert check(5724) is True
    assert checksum(43881234567) == 9
