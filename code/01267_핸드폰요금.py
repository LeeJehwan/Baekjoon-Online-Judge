n = int(input())
y = 0
m = 0
feel = map(int,input().split())
for fee in feel:
   y += 10*(fee//30 + 1)
   m += 15*(fee//60 + 1)

if y < m:
    print("Y",y)
elif y==m:
    print("Y M",y)
else:
    print("M",m)