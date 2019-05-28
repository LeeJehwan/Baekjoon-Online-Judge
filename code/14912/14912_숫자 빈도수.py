n, m = map(int, input().split())
ans = 0
for x in range(1,n+1):
    ans += str(x).count(str(m))
print(ans)