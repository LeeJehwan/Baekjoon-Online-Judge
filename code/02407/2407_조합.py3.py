n,m=map(int,input().split())
comb =[[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, i+1):
        if i == j:
            comb[i][j] = 1
        elif j == 1:
            comb[i][j] = i
        else:
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j]

print(comb[n][m])
