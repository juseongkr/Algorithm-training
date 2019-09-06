h, m, s = map(int, input().split(':'))
H, M, S = map(int, input().split(':'))
x = s + 60*m + 3600*h
y = S + 60*M + 3600*H
if y > x:
    print(y-x)
else:
    print(86400-x+y)
