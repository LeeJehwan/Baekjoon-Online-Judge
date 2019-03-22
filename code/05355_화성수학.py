t = int(input())
for _ in range(t):
    x, *l = input().split()
    x = float(x)
    for y in l:
        if y == '@':
            x *= 3
        elif y == '%':
            x += 5
        elif y == '#':
            x -= 7
    print("%0.2f" % x)


