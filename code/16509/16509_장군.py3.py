import queue

def is_range(a, b):
    if 0 <= a <= 9 and 0 <= b <= 8:
        return True
    else:
        return False

chk = [[0] * 9 for _ in range(10)]
sang = list(map(int, input().split()))
king = list(map(int, input().split()))
q = queue.Queue()
q.put(sang)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
ctl = 1
chk[sang[0]][sang[1]] = 1
while not q.empty():
    pos = q.get()
    if pos == king:
        ctl = 0
        print(chk[king[0]][king[1]]-1)

    for i in range(4):
        nx = pos[0] + dx[i]
        ny = pos[1] + dy[i]
        if is_range(nx, ny) and [nx, ny] != king:
            for x in [3, 1]:
                nx2 = nx
                ny2 = ny
                go = True
                for j in range(2):
                    nx2 += dx[i] + dx[(i+x) % 4]
                    ny2 += dy[i] + dy[(i+x) % 4]
                    if (not is_range(nx2, ny2)) or (j == 0 and [nx2, ny2] == king):
                        go = False
                if go and not chk[nx2][ny2]:
                    chk[nx2][ny2] = chk[pos[0]][pos[1]] + 1
                    q.put([nx2, ny2])

if ctl:
    print(-1)