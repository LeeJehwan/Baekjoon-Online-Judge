n = int(input())
sum = 0
for i in range(n):
    x, y = map(int, input().split())
    sum += y % x
print(sum)