a,b =input(),input()

print(sum(abs(a.count(x)-b.count(x)) for x in {*a+b}))