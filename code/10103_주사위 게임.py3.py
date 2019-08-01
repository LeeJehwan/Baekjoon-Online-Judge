n = int(input())

sumx = 100
sumy = 100
for i in range(n):
    x, y = map(int,input().split())
    if x > y :
        sumy -= x
    elif x < y:
        sumx -= y

print(sumx)
print(sumy)