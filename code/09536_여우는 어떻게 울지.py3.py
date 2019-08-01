n = int(input())
for i in range(n):
    sound = list(input().split())
    
    d = dict()
    while True:
        x = input()
        if x == "what does the fox say?":
            break
        l = x.split()
        ss = sound.copy()
        for k in ss:
            if l[2] == k:
                sound.remove(k)
    for x in sound:
        print(x, end=' ')
        
        
        