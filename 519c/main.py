import sys

n, m = map(int, sys.stdin.readline().split())
if n < m:
    m, n = n, m
if 2 * m <= n:
    print(m)
else:
    print((n + m) // 3)
