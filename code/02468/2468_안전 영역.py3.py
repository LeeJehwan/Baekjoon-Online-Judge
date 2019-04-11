from sys import *
setrecursionlimit(10 ** 6)

n = int(input())
chk = []
rain = []
high = 0
low = 10000000000
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(x, y, level):
    chk[x][y] = 1

    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]

        if 0 <= nx < n and 0 <= ny < n:
            if chk[nx][ny] == 0 and level < rain[nx][ny]:
                dfs(nx, ny, level)


for i in range(n):
    rain.append(list(map(int, input().split())))
for i in rain:
    high = max(high, max(i))
for i in rain:
    low = min(low, min(i))
cnt = [0] * (high + 1)
for i in range(low):
    cnt[i] = 1

for lev in range(low, high + 1):
    chk = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if chk[i][j] == 0 and lev < rain[i][j]:
                cnt[lev] += 1
                dfs(i, j, lev)

print(max(cnt))
