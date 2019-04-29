import hashlib
h = hashlib.md5()
h.update(input().encode())
print(h.hexdigest())
