import hashlib
h = hashlib.sha1()
h.update(input().encode())
print(h.hexdigest())
