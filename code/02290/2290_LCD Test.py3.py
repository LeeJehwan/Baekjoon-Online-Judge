s, num = input().split()
s = int(s)

w = s + 2
h = 2*s + 3

arr = [[' ']*(w+1)*len(num) for _ in range(h)]
for x, i in zip(num, range(len(num))):
    if x == '1':
       for y in range(h):
           if y not in [0, (h-1)//2, h-1]:
                arr[y][(w+1)*i + w - 1] = '|'
    elif x == '2':
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(1, (h-1)//2):
            arr[y][(w + 1) * i + w - 1] = '|'
        for y in range((h-1)//2+1, h-1):
            arr[y][(w + 1) * i] = '|'
    elif x == '3':
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
    elif x == '4':
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(1, (h-1)//2):
            arr[y][(w + 1) * i] = '|'
        for y in range(1,w-1):
            arr[(h-1)//2][y+(w+1)*i] = '-'
    elif x == '5':
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(1, (h-1)//2):
            arr[y][(w + 1) * i] = '|'
        for y in range((h-1)//2+1, h-1):
            arr[y][(w + 1) * i + w - 1] = '|'
    elif x == '6':
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range((h-1)//2+1, h-1):
            arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i] = '|'
    elif x == '7':
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
    elif x == '8':
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i] = '|'
    elif x == '9':
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[(h-1)//2][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(1, (h-1)//2):
            arr[y][(w + 1) * i] = '|'
    elif x == '0':
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i + w - 1] = '|'
        for y in range(1,w-1):
            arr[0][y+(w+1)*i] = '-'
            arr[h-1][y+(w+1)*i] = '-'
        for y in range(h):
            if y not in [0, (h - 1) // 2, h - 1]:
                arr[y][(w + 1) * i] = '|'

for x in arr:
    for y in x:
        print(y, end ="")
    print()