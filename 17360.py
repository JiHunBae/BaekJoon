import sys

def solve():
    n,m,k = map(int, sys.stdin.readline().split(' '))
    divisor = pow(10, 9) + 7
    if (k is 1) or k > n:
        result = pow(m, n) % divisor
    elif k == n:
        result = pow(m, int((n+1)/2)) % divisor
    elif k % 2 is 0:
        result = m % divisor
    else:
        result = pow(m, 2) % divisor

    print(result)

solve()