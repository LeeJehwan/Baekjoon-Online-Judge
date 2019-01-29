n, m = map(int, input().split())
l = list()

def dfs():
    if len(l) == m:
        print(*l)
        return
    for i in range(1, n+1):
        if i in l:
            continue
        if len(l) > 0 and i < l[len(l)-1]:
            continue
        l.append(i)
        dfs()
        l.pop()

dfs()