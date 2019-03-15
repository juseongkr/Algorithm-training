def self_number(n):
    backup = n
    s = 0
    while n:
        s += (n % 10)
        n = int(n / 10)

    return int(s) + backup

li = [i for i in range(10000)]

for i in range(10000):
    if self_number(i) in li:
        li.remove(self_number(i))

for i in li:
    print(i)
