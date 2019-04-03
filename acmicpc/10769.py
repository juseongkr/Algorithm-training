n = input()
A, B = ":-)", ":-("
h, s = 0, 0
for i in range(len(n)-3):
    if n[i:i+3] == A:
        h += 1
    if n[i:i+3] == B:
        s += 1
if h == 0 and s == 0:
    print("none")
elif h == s:
    print("unsure")
elif h < s:
    print("sad")
else:
    print("happy")
