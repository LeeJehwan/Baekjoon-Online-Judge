t = int(input())

for _ in range(t):
    n = input()
    nr = n[::-1]
    ans = int(n) + int(nr)
    ans = str(ans)
    if ans == ans[::-1]:
        print("YES")
    else:
        print("NO")