t = int(input())
for _ in range(t):
    a=0
    b=0
    for h in range(9):
        x,y = map(int,input().split())
        a+=x
        b+=y
    if a > b:
        print("Yonsei")
    elif a==b:
        print("Draw")
    else:
        print("Korea")