a = input()

for i in ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']:
    a=a.replace(i, 'a')
print(len(a))
