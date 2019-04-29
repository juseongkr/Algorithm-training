import base64
h = base64.b64encode(input().encode())
print(h.decode())
