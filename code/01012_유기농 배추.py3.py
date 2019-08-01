import queue

chk = [[0] * 50 for i in range(50)]
lec = [[0] * 50 for i in range(50)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y, n, m):
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

            if 0 <= nx < n and 0 <= ny < m:
                if chk[nx][ny] == 0 and lec[nx][ny] == 1:
                    chk[nx][ny] = 1
                    q.put((nx, ny))


def main():
    t = int(input())
    for ti in range(t):
        m, n, k = map(int, input().split())

        for i in range(n):
            for j in range(m):
                chk[i][j] = 0
                lec[i][j] = 0

        for i in range(k):
            y, x = map(int, input().split())
            lec[x][y] = 1

        cnt = 0
        for i in range(n):
            for j in range(m):
                if lec[i][j] == 1 and chk[i][j] == 0:
                    cnt += 1
                    bfs(i, j, n, m)

        print(cnt)


main()