import math
n = int(input())
a = int(math.sqrt(n))
if n*n == a:
    print(a)
else:
    print(a+1)