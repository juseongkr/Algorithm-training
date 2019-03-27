k = int(input())
y, n = 0, 0
for _ in range(k):
    t = input()
    if t == '1':
        y += 1
    else:
        n += 1
    
if y > n:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")
