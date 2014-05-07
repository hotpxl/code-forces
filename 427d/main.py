import sys

def repeatingSubString(s):
    mat = [[0 for i in range(len(s))] for i in range(len(s))]
    ret = [0 for i in range(len(s))]
    for i in range(1, len(s)):
        if s[i] == s[0]:
            mat[0][i] = 1
            ret[i] = 1
            ret[0] = 1
    for i in range(1, len(s)):
        for j in range(i + 1, len(s)):
            if s[i] == s[j]:
                mat[i][j] = mat[i - 1][j - 1] + 1
                if ret[i] < mat[i][j]:
                    ret[i] = mat[i][j]
                if ret[j] < mat[i][j]:
                    ret[j] = mat[i][j]
    return ret

def commonSubString(s1, r1, s2, r2):
    ret = 65535
    mat = [[0 for i in range(len(s1))] for i in range(len(s2))]
    for i in range(len(s1)):
        if s1[i] == s2[0]:
            mat[0][i] = 1
            if r1[i] < 1 and r2[0] < 1:
                ret = 1
    for i in range(len(s2)):
        if s1[0] == s2[i]:
            mat[i][0] = 1
            if r1[0] < 1 and r2[i] < 1:
                ret = 1
    if ret == 1:
        return ret
    for i in range(1, len(s2)):
        for j in range(1, len(s1)):
            if s1[j] == s2[i]:
                cur = mat[i - 1][j - 1] + 1
                mat[i][j] = cur
                if r1[j] < cur and r2[i] < cur:
                    newMin = max(r1[j], r2[i]) + 1
                    if newMin < ret:
                        ret = newMin
    if ret == 65535:
        return -1
    return ret

if __name__ == '__main__':
    s1 = sys.stdin.readline().strip()
    s2 = sys.stdin.readline().strip()
    print(''.join(map(str, repeatingSubString(s1))))
    print(commonSubString(s1, repeatingSubString(s1), s2, repeatingSubString(s2)))

