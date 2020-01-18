import re
for _ in range(int(input())):
    if re.match("(100+1+|01)+$", input()):
        print("YES")
    else:
        print("NO")
