l = list()
for i in range(31):
    l.append(pow(2,i))
a = int(input())
if a in l:
    print(1)
else:
    print(0)