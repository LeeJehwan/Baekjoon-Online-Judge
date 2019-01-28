import queue


def bfs(x, y):
    q = queue.Queue()
    chk[x][y] = 1
    q.put((x, y))

    while not q.empty():
        front = q.get()
        x = front[0]
        y = front[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                if chk[nx][ny] == 0 and pic[nx][ny] == pic[x][y]:
                    chk[nx][ny] = 1
                    q.put((nx, ny))


dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
n = int(input())
chk = [[0] * n for i in range(n)]
pic = list()
for i in range(n):
    pic.append(list(input()))

cnt1 = 0
for i in range(n):
    for j in range(n):
        if chk[i][j] == 0:
            cnt1 += 1
            bfs(i, j)

for i in range(n):
    for j in range(n):
        if pic[i][j] == 'G':
            pic[i][j] = 'R'
        chk[i][j] = 0

cnt2 = 0
for i in range(n):
    for j in range(n):
        if chk[i][j] == 0:
            cnt2 += 1
            bfs(i, j)

print(cnt1, cnt2)