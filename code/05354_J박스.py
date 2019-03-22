t = int(input())
for _ in range(t):
    x = int(input())
    l = [['#']* x for _ in range(x)]
    for i in range(1,x-1):
        for j in range(1,x-1):
            l[i][j] ='J'
    for k in l:
        for z in k:
            print(z, end='')
        print()
    print()