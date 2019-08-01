import queue

n, m = map(int, input().split())
l = []
for i in range(n):
    l.append(list(map(int, input().split())))
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
chk = [[0]*m for _ in range(n)]


def bfs(x, y):
    q = queue.Queue()
    q.put([x, y])
    chk[x][y] = 1
    size = 1
    while not q.empty():
        tmp = q.get()
        for i in range(4):
            nx = tmp[0] + dx[i]
            ny = tmp[1] + dy[i]
            if 0 <= nx < n and 0 <= ny < m and chk[nx][ny] == 0 and l[nx][ny]:
                chk[nx][ny] = 1
                size += 1
                q.put([nx,ny])
    return size

cnt = 0
ans = 0
for i in range(n):
    for j in range(m):
        if 0 <= i < n and 0 <= j < m and chk[i][j] == 0 and l[i][j]:
            cnt += 1
            ans = max(ans,bfs(i,j))

print(cnt)
print(ans)
