for _ in range(int(input())):
    clothes = {}
    for i in range(int(input())):
        x, y = input().split()
        if y in clothes:
            clothes[y] += 1
        else:
            clothes[y] = 1

    ans = 1
    for key, value in clothes.items():
        ans *= (value+1)

    print(ans-1)

