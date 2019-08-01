t = int(input())
for _ in range(t):
    s = list(input().split())
    for x in s:
        print(x[::-1],end=' ')
    print()