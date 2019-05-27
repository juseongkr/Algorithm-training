s, r = "", 0
while True:
    try:
        n = input()
    except EOFError:
        break
    s += n
for i in s.split(','):
    r += int(i)
print(r)
