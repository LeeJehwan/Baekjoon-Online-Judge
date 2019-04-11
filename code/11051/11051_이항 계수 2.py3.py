n, k = map(int, input().split())

dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(n+1):
    for j in range(i+1):
        if j > k: break
        if i == j:
            dp[i][j] = 1
            continue
        if j == 0:
            dp[i][j] = 1
            continue
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007

print(dp[n][k]%10007)
