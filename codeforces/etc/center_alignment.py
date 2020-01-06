import sys

m = 0
l = []

for i in sys.stdin:
    l.append(i.rstrip())
    m = max(len(l[-1]), m)

flag = True
print('*' * (m + 2))
for i in l:
    s = m - len(i)
    a = s // 2
    b = s - a
    if a != b:
        if not flag:
            a, b = b, a
        flag = not flag
    print('*' + (' ' * a) + i + (' ' * b) + '*')
print('*' * (m + 2))
