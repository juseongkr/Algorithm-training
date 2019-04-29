import hashlib
h = hashlib.sha384()
h.update(input().encode())
print(h.hexdigest())
