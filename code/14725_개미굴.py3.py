n = int(input())
l = list()
for _ in range(n):
    l.append('/'.join(input().split()[1:]))
l = sorted(l)
now_dir = ""
last_l = []
for x in l:
    t = x.split('/')
    flag = 1
    for (y, i) in zip(t, range(len(t))):

        if flag:
            if len(last_l)-1 >= i and t[i] == last_l[i]:
                continue
            else:
                flag = 0

        print('--'*i, end="")
        print(y)
    last_l = t