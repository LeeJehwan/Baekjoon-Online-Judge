n=int(input())
h=[]
for _ in range(n):
    h.append(list(map(int,input().split())))
for i in range(1,n):
    for j in range(3):
        h[i][j] = min(h[i-1][(j+1)%3], h[i-1][(j+2)%3]) + h[i][j]
print(min(h[n-1]))