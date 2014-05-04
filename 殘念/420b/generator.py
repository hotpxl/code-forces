import sys
import random

if __name__ == '__main__':
    with open('in_large', 'w') as f:
        flags = ['+', '-']
        f.write('%d %d\n' % (100000, 100000))
        for i in range(100000):
            f.write(random.choice(flags))
            f.write(' %d\n' % random.randint(1, 100000))

