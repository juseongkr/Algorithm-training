for _ in range(int(input())):
    a = input()
    b = input()
    r = 0
    for i, j in zip(a, b):
        if i != j:
            r += 1
    print("Hamming distance is {}.".format(r))
