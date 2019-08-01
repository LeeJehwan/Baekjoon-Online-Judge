import queue
n,k = map(int,input().split())
q = queue.Queue()
q.put(n)
chk = [0]*100001
while not q.empty():
    x = q.get()
    if x == k:
        print(chk[k])
        break

    nx = x - 1
    if 0 <= nx <= 100000 and chk[nx]==0:
        chk[nx]=chk[x] +1
        q.put(nx)

    nx = x + 1
    if 0 <= nx <= 100000 and chk[nx]==0:
        chk[nx]=chk[x] +1
        q.put(nx)

    nx = 2*x
    if 0 <= nx <= 100000 and chk[nx] == 0:
        chk[nx] = chk[x] + 1
        q.put(nx)
