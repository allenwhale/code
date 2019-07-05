from __future__ import print_function
import math
from decimal import *

getcontext().prec = 300


def S(n):
    if n == Decimal(0):
        return Decimal(0)
    nn = ((Decimal(2).sqrt() - Decimal(1)) * Decimal(n)).quantize(
        Decimal(0), rounding=ROUND_FLOOR)
    return n * nn + (n * (n + Decimal(1))) // Decimal(2) - (
        nn * (nn + Decimal(1))) // Decimal(2) - S(nn)


ANS = [0] * 100000


def solution(s):
    return format(S(Decimal(s)), '.0f')


if __name__ == "__main__":
    print(solution("77"))
    print(solution("5"))
    # for i in range(100):
    #     print(solution(str(10**i)))
