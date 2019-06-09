n, r = input(), 0
for i in range(len(n)):
    r = (r * 10 + int(n[i])) % 20000303
print(r)
