alpha = ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']

s = input()
ans = len(s)
for x in alpha:
    if x in s:
        ans -= s.count(x)

if 'dz=' in s:
    ans -= s.count('dz=')

print(ans)
