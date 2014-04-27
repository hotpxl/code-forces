import sys

if __name__ == '__main__':
    participantNum, messageNum = map(int, sys.stdin.readline().split())
    messages = [sys.stdin.readline().split() for i in range(messageNum)]
    for i in messages:
        i[1] = int(i[1])
    nonExistent = ((1 << participantNum) - 1) << 1
    online = 0
    offlineAtFirst = 0
    for i in messages:
        if i[0] == '+':
            offlineAtFirst |= (1 << i[1])
        else:
            if not offlineAtFirst & (1 << i[1]):
                online |= (1 << i[1])
    nonExistent &= ~(online | offlineAtFirst)
    possible = ((1 << participantNum) - 1) << 1
    offline = possible & ~(nonExistent | online)
    if online:
        possible &= ~offline
    for i in messages:
        num = (1 << i[1])
        if i[0] == '+':
            offline &= ~num
            online |= num
            if online:
                possible &= ~offline
        else:
            offline |= num
            online &= ~num
            if online:
                possible &= ~num
    possible |= nonExistent
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

