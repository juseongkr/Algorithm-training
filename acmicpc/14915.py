s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(n, b):
    return "0" if not n else to_base(n//b, b).lstrip("0") + s[n%b]
n, m = map(int, input().split())
print(to_base(n, m))
