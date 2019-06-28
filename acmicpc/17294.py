n, flag = input(), False
for i in range(2, len(n)):
    if (int(n[i]) - int(n[i-1]) != int(n[i-1]) - int(n[i-2])):
        flag = True
        break
if len(n) == 1:
    flag = False
if flag:
    print("흥칫뿡!! <(￣ ﹌ ￣)>")
else:
    print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
