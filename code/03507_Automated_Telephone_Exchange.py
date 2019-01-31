n = int(input())
ans = 0
for i in range(100):
    for j in range(100):
        if n == i + j:
            ans += 1
print(ans)