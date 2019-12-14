x, y = map(int, input().split())
X, Y = map(int, input().split())
t = int(input())
print("{} {}".format(x-abs(x-(X+t)%(2*x)), y-abs(y-(Y+t)%(2*y))))
