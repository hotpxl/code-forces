import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    police = 0
    crime = 0
    for i in map(int, sys.stdin.readline().split()):
        if 0 < i:
            police += i
        elif 0 < police:
            police -= 1
        else:
            crime += 1
    print(crime)

