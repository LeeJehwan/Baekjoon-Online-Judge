s1 = list(map(int, input().split(':')))
s2 = list(map(int, input().split(':')))
t1 = s1[0] * 3600 + s1[1] * 60 + s1[2]
t2 = s2[0] * 3600 + s2[1] * 60 + s2[2]
t2 -= t1
if t2 < 0:
    t2 += 3600 * 24
a = [t2//3600]
a.append((t2-a[0]*3600)//60)
a.append((t2-a[0]*3600)%60)
print('{0:0>2}:{1:0>2}:{2:0>2}'.format(a[0], a[1], a[2]))