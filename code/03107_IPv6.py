l = input()
if '::' in l:
    x = l.count(':')-2
    idx = l.find('::')
    if idx == 0:
        l =l.replace("::", "0:"*(7-x))
    elif idx == len(l)-2:
        l = l.replace('::', ':0'*(7-x))
    else:
        l = l.replace('::',':0'*(6-x)+':')
l = l.split(':')

print(':'.join(["{0:0>4}".format(x) for x in l]))