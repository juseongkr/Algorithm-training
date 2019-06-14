for _ in range(int(input())):
    n = int(input())
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == 1 or j == 1 or i == n or j == n:
                print('#', end='')
            else:
                print('J', end='')
        print()
    print()
