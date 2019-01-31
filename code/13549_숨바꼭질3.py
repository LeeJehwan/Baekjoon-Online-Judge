import collections

n, k = map(int, input().split())
d = collections.deque()
d.append(n)
chk = [0]*100001
chk[n] = 1
while len(d):
    x = d.popleft()
    if x == k:
        print(chk[k]-1)
        break

    for nx in [x-1, x+1, 2*x]:
        if 0 <= nx <= 100000 and chk[nx]==0:
            if nx == 2*x:
                chk[nx] = chk[x]
                d.appendleft(nx)
            else:
                chk[nx]=chk[x] +1
                d.append(nx)

