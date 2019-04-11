dp = [[0]*2 for _ in range(45)]

def fib(num):
    dp[0][0] = 1
    dp[1][1] = 1
    
    for i in range(2,num+1):
        dp[i][0] = dp[i-1][0] + dp[i-2][0]
        dp[i][1] = dp[i-1][1] + dp[i-2][1]

n = int(input())
for _ in range(n):
    n2 = int(input())
    fib(n2)
    print(dp[n2][0],dp[n2][1])