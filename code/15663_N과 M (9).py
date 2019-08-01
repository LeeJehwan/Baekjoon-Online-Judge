from itertools import permutations

n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

p = sorted(list(set(permutations(a, m))))
for x in p:
    print(*x)
