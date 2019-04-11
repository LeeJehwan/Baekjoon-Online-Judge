def dfs(s, cnt):
    chk[s] = 1
    for h in com[s]:
        if chk[h] == 0:
            cnt[0] += 1
            dfs(h, cnt)


n = int(input())
k = int(input())
com = [[] for i in range(n+1)]
chk = [0]*(n+1)

for _ in range(k):
    x, y = map(int, input().split())
    com[x].append(y)
    com[y].append(x)

cnt = [0]
dfs(1, cnt)
print(cnt[0])