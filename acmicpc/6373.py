import sys

def check(s):
    for i in range(1, len(s)+1):
        if s not in str(int(s) * i).zfill(len(s)) * 2:
            return False
    return True

for s in sys.stdin.readlines():
    s = s[:-1]
    if check(s):
        print(s + " is cyclic")
    else:
        print(s + " is not cyclic")
