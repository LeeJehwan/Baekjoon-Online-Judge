from sys import *
setrecursionlimit(10 ** 6)
import queue
n,k = map(int,input().split())
q = queue.Queue()
q.put(n)
chk = [0]*100001
rout = [0]*100001
while not q.empty():
    x = q.get()
    if x == k:
        print(chk[k])
        break

    for nx in [x-1, x+1,x*2]:
        if 0 <= nx <= 100000 and chk[nx]==0:
            chk[nx]=chk[x] +1
            rout[nx] = x
            q.put(nx)

def print_r(cnt):
    if cnt == n:
        return
    print_r(rout[cnt])
    print(cnt, end=" ")

print(n, end=" ")
print_r(k)