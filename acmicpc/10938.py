import base64
h = base64.b32encode(input().encode())
print(h.decode())
