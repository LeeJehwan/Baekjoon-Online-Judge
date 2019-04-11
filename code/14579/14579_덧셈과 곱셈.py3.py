a, b = map(int,input().split())
ans = 1
for x in range(a,b+1):
    tmp = int((x*(x+1))/2)
    ans*=tmp
print(ans%14579)