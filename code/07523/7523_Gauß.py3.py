t = int(input())
for i in range(1,t+1):
    x, y = map(int, input().split())
    s = x + y
    cnt = y - x + 1
    print("Scenario #"+str(i)+":")
    print(int((s*cnt)//2))
    print()