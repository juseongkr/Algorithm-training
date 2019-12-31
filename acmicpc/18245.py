l = 1
while 1:
    l += 1
    s = input()
    if s == "Was it a cat I saw?":
        break
    print(s[::l])
