input()
l = [*map(lambda i: int(i, 16), input().split())]
print(''.join(["." if i < 32 else "-"  for i in l]))
