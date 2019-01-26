t = int(input())
for i in range(t):
    s = input()
    if s == "P=NP":
        print("skipped")
    else:
        l = s.split('+')
        a = int(l[0])+int(l[1])
        print(a)