n = int(input())
l = list()
for _ in range(n):
    l.append(input())
k = int(input())
if k == 1:
    for x in l:
        print(x)
elif k == 2:
    for x in l:
        print(x[::-1])
else:
    for x in range(n-1, -1, -1):
        print(l[x])


