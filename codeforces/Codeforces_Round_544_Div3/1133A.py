sh, sm = input().split(':')
eh, em = input().split(':')
end = int(eh)*60 + int(em)
start = int(sh)*60 +int(sm)
ans = (start+end)//2
print("{:02d}:{:02d}".format(ans//60, ans%60))
