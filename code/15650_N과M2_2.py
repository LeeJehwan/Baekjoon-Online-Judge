from itertools import combinations as cb
n, m = map(int,input().split())
for i in cb(range(1,n+1),m):
    print(*i)

