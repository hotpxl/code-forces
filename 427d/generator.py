import random

dictionary = []
for i in range(26):
    dictionary.append(chr(i + ord('a')))
for i in range(5000):
    print(random.choice(dictionary), end='')
print()
for i in range(5000):
    print(random.choice(dictionary), end='')
print()

