import sys

if __name__ == '__main__':
    n, s = map(int, sys.stdin.readline().split())
    mugs = list(sorted(map(int, sys.stdin.readline().split())))
    if sum(mugs[:n - 1]) <= s:
        print('YES')
    else:
        print('NO')

