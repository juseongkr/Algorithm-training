import hashlib
h = hashlib.sha256()
h.update(input().encode())
print(h.hexdigest())
