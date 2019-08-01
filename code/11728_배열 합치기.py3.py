n, m = map(int, input().split())
a = list()
b = list()

a = map(int, input().split())
b = map(int, input().split())
a = list(a)
b = list(b)

c = a + b
c.sort()
for i in c:
    print(i, end=' ')
            