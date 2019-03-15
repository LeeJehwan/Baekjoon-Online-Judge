l = input().split()
for x in range(1, len(l)):
    l[x] = l[x][:-1]
for x, i in zip(l, range(len(l))):
    if i == 0: continue
    t= ""
    k = ""
    for y in x:
        if 'a' <= y <= 'z' or 'A' <= y <='Z':
            t += y
        else:
            k += y
    fi = l[0] + k[::-1].replace('][', '[]')
    print(fi, t+';')
