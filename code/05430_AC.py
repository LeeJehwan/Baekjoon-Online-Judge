import collections
t = int(input())
for _ in range(t):
    s = input()
    n = int(input())
    l = input()[1:-1].split(',')
    if l[0] == '':
        l = []

    d = collections.deque(l)
    flag = 1
    lr = 0
    for x in s:
        if x == 'R':
            lr = lr ^ 1
        else:
            if len(d) == 0:
                flag = 0
                print("error")
                break
            elif not lr:
                d.popleft()
            else:
                d.pop()

    ll = []
    for x in d:
        ll.append(x)

    if lr:
        ll = ll[::-1]
    if flag:
        ans = '[' + ','.join(ll) + ']'
        print(ans)
