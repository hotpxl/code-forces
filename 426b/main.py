import sys

def mirror(row, matrix):
    if row % 2:
        return row
    else:
        for i in range(row // 2):
            if matrix[i] != matrix[row - 1 - i]:
                return row
        return mirror(row // 2, matrix)

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())
    matrix = [list(map(int, i.split())) for i in sys.stdin.readlines()]
    print(mirror(n, matrix))

