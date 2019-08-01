n = int(input())
people = list()

pb = dict()
for x in range(n):
    tmp = input().split()
    if tmp[1] == "enter":
        pb[tmp[0]] = 1
    else:
        pb[tmp[0]] = 0

for x in pb:
    if pb[x] == 1:
        people.append(x)

people = sorted(people, reverse= True)
for x in people:
    print(x)

