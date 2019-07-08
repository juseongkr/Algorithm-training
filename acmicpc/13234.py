a, o, b = input().split()
if o == "OR":
    if a == "true" or b == "true":
        print("true")
    else:
        print("false")
else:
    if a == "true" and b == "true":
        print("true")
    else:
        print("false")
