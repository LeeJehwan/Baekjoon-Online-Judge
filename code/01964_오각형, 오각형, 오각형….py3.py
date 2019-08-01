n = int(input())
ans = [0]*10000001
ans[1] = 5

for i in range(2,n+1):
    ans[i] = (ans[i-1] + 3*i + 1)%45678
print(ans[n])