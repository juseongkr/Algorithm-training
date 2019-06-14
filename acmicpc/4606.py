m = {' ':'%20', '!':'%21', '$':'%24', '%':'%25', '(':'%28', ')':'%29', '*':'%2a'};
while True:
    s = input()
    if s == '#':
        break
    for i in s:
        if i in m:
            print(m[i], end='')
        else:
            print(i, end='')
    print()
