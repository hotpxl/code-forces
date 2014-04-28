import sys

if __name__ == '__main__':
    participantNum, messageNum = map(int, sys.stdin.readline().split())
    online = 0
    notPresent = ((1 << participantNum) - 1) << 1
    flag, num = sys.stdin.readline().split()
    num = 1 << int(num)
    notPresent &= ~num
    possible = num
    if flag == '+':
        online |= num
    for i in range(messageNum - 1):
        flag, num = sys.stdin.readline().split()
        num = 1 << int(num)
        notPresent &= ~num
        if flag == '+':
            if not online and num != possible:
                possible = 0
            online |= num
        else:
            if num != possible:
                if not num & online:
                    if not online:
                        possible = num
                    else:
                        possible = 0
                online &= ~num
            else:
                online &= ~num
                if online != 0:
                    possible = 0
    if online and not possible & online:
        possible = 0
    possible |= notPresent
    if possible:
        counter = 0
        boss = []
        while possible:
            possible >>= 1
            counter += 1
            if possible & 0x01:
                boss.append(counter)
        print(len(boss))
        print(' '.join(map(str, boss)))
    else:
        print(0)

