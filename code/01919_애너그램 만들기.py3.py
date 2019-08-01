a = input()
b = input()
a_s = set(','.join(a).split(','))
b_s = set(','.join(b).split(','))

uni = a_s.union(b_s)
inter = a_s.intersection(b_s)
c = uni.difference(inter)
ans = 0
for x in c:
    if x in a:
        ans+=a.count(x)
    else:
        ans+=b.count(x)

for x in inter:
    x1 = a.count(x)
    x2 = b.count(x)
    if x1 > x2:
        ans += (x1-x2)
    elif x1 < x2:
        ans += (x2-x1)

print(ans)