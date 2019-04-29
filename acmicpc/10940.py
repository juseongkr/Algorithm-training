import base64
h = base64.b16encode(input().encode())
print(h.decode())
