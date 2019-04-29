import hashlib
h = hashlib.sha512()
h.update(input().encode())
print(h.hexdigest())
