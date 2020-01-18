import re
if re.match("(100+1+|01)+$", input()):
    print("SUBMARINE")
else:
    print("NOISE")
