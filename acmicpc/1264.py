while True:
    n = input()
    if n == '#':
        break
    cnt = 0
    for i in n:
        i = i.lower()
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            cnt += 1
    print(cnt)
