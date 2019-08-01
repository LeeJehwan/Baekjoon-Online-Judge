import queue
n,k = map(int,input().split())
q = queue.Queue()
q.put(n)

vis = [False]*100001
chk = [0]*100001
nb = [0]*100001
vis[n] = True

while not q.empty():
    x = q.get()
    for nx in [x-1, x+1, x*2]:
        if 0 <= nx <= 100000:
            if not vis[nx]:
                chk[nx] = chk[x] + 1
                vis[nx] = True
                q.put(nx)
            elif chk[nx] == chk[x]+1:
                if nx == k:
                    nb[chk[nx]] += 1
                q.put(nx)

print(chk[k])
print(nb[chk[k]]+1)