import sys

for i in range(3):
    n = int(input())
    a = [sys.stdin.readline() for i in range(n)]
    s = sum(list(map(int, a)))
    if s == 0:
        print(0)
    elif s > 0:
        print('+')
    else:
        print('-')