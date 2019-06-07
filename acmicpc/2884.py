h, m = map(int, input().split())
m += h*60-45
if m < 0:
    m += 24*60
print(m//60, end=' ')
print(m%60)
