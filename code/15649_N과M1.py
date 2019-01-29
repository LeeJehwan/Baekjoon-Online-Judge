l = list()
def dfs():
    if len(l) == m:
        for x in l:
            print(x, end=" ")
        print()
        return
    for i in range(1, n+1):
        if i in l:
            continue
        l.append(i)
        dfs()
        l.pop()


n, m = map(int, input().split())
dfs()