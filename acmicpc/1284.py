while True:
    n = input()
    if n == '0':
        break
    cnt = len(n)+1
    for i in n:
        if i == '1':
            cnt += 2
        elif i == '0':
            cnt += 4
        else:
            cnt += 3
    print(cnt)
