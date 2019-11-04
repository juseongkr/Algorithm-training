s = input()
s = ''.join(i for i in s if not i.isdigit())
p = input()
if p in s:
    print(1)
else:
    print(0)
