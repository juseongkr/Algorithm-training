s = input().split()
s = [i.rstrip(',;') for i in s]
for i in s[1:]:
    v, k = "", ""
    for j in i[::-1]:
        if j.isalpha():
            v += j
        elif j == ']':
            k += '[]'
        elif j == '[':
            continue
        else:
            k += j
    print(s[0]+k+' '+v[::-1]+';')
