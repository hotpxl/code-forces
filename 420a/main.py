import sys

def check(text):
    legal = 'AHIMOTUVWXY'
    for i in text:
        if i not in legal:
            return False
    rev = list(text)
    rev.reverse()
    if text != ''.join(rev):
        return False
    return True

if __name__ == '__main__':
    text = sys.stdin.readline().split()[0]
    if check(text):
        print('YES')
    else:
        print('NO')

