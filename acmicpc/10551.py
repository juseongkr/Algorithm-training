l = [0]*8
for i in input():
    if i in ['1', 'Q', 'A', 'Z']:
        l[0] += 1
    elif i in ['2', 'W', 'S', 'X']:
        l[1] += 1
    elif i in ['3', 'E', 'D', 'C']:
        l[2] += 1
    elif i in ['4', 'R', 'F', 'V', '5', 'T', 'G', 'B']:
        l[3] += 1
    elif i in ['6', 'Y', 'H', 'N', '7', 'U', 'J', 'M']:
        l[4] += 1
    elif i in ['8', 'I', 'K', ',']:
        l[5] += 1
    elif i in ['9', 'O', 'L', '.']:
        l[6] += 1
    else:
        l[7] += 1
for i in l:
    print(i)
