import sys

if __name__ == '__main__':
    participantNum, messageNum = map(int, sys.stdin.readline().split())
    messages = [sys.stdin.readline().split() for i in range(messageNum)]
    for i in messages:
        i[1] = int(i[1])
    nonExistent = set(range(1, participantNum + 1))
    online = set()
    offlineAtFirst = set()
    for i in messages:
        nonExistent.discard(i[1])
        if i[0] == '+':
            offlineAtFirst.add(i[1])
        else:
            if i[1] not in offlineAtFirst:
                online.add(i[1])
    nonExistent -= online | offlineAtFirst
    possible = set(range(1, participantNum + 1))
    offline = possible - nonExistent - online
    if online:
        possible -= offline
    for i in messages:
        if i[0] == '+':
            offline.discard(i[1])
            online.add(i[1])
        else:
            offline.add(i[1])
            online.discard(i[1])
        if online:
            possible -= offline
    possible |= nonExistent
    if possible:
        print(len(possible))
        print(' '.join(map(str, sorted(list(possible)))))
    else:
        print(0)

