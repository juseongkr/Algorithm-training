x, y, w, h = map(int, input().split())
print(min(min(w-x, x), min(h-y, y)))
