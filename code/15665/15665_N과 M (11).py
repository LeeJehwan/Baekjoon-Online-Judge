from itertools import product

n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

p = sorted(list(set(product(a, repeat=m))))
for x in p:
    print(*x)