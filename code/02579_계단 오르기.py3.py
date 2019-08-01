n = int(input())
stair = [0] * (n+1)

for i in range(1, n+1):
    stair[i] = int(input())

dp = [[0] * 3 for _ in range(n+1)]

dp[1][1] = stair[1]
for i in range(2, n+1):
    dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stair[i]
    dp[i][2] = dp[i-1][1] + stair[i]

print(max(dp[n][1], dp[n][2]))