n = int(input())
while True:
    t = input()
    if t == '0':
        break
    if int(t) % n == 0:
        print(t + " is a multiple of " + str(n) + ".")
    else:
        print(t + " is NOT a multiple of " + str(n) + ".")
