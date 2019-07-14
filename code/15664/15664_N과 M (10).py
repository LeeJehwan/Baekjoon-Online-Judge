from itertools import combinations

n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

p = sorted(list(set(combinations(a, m))))
for x in p:
    print(*x)