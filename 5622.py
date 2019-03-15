n = input()
cnt = 0

for i in n:
    if 'A' <= i <= 'C':
        cnt += 3
    elif 'D' <= i <= 'F':
        cnt += 4
    elif 'G' <= i <= 'I':
        cnt += 5
    elif 'J' <= i <= 'L':
        cnt += 6
    elif 'M' <= i <= 'O':
        cnt += 7
    elif 'P' <= i <= 'S':
        cnt += 8
    elif 'T' <= i <= 'V':
        cnt += 9
    elif 'W' <= i <= 'Z':
        cnt += 10
    elif i == 0:
        cnt += 11
    elif i == 1:
        cnt += 2

print(cnt)
