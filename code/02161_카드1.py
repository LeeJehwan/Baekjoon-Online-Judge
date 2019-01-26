n = int(input())
l = list()
for i in range(1, n+1):
    l.append(i)
while True:
    if len(l) == 1:
        break
    print(l[0], end=' ')
    l = l[1:]
    l.append(l[0])
    l = l[1:]
print(l[0])