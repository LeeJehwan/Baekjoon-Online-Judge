l = [x for x in range(1, 21)]
for _ in range(10):
    a, b= map(int, input().split())
    l[a-1:b] = reversed(l[a-1:b])
print(*l)