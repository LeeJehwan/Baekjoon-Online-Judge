l =[]
s = 0
for i in range(5):
    l.append(int(input()))
    s += l[i]
print(int(s/5))
print(sorted(l)[2])