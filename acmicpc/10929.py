import hashlib
h = hashlib.sha224()
h.update(input().encode())
print(h.hexdigest())
