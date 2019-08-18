a, b, c = map(int, input().split())
m = min(a, b, c)
if a + b + c >= 100:
    print("OK")
elif m == a:
    print("Soongsil")
elif m == b:
    print("Korea")
elif m == c:
    print("Hanyang")
