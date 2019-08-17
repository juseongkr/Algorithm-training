#include <iostream>
using namespace std;
#define ll long long
typedef pair<ll, ll> Point;
typedef pair<Point, Point> Line;

int ccw(Point p1, Point p2, Point p3)
{
	ll t = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	t = t - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;
	if (t > 0)
		return 1;
	else if (t < 0)
		return -1;
	else
		return 0;
}

bool check(Line l1, Line l2)
{
	int x = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
	int y = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);

	if (x == 0 && y == 0) {
		if (l1.first > l1.second)
			swap(l1.first, l1.second);

		if (l2.first > l2.second)
			swap(l2.first, l2.second);

		if (l2.first <= l1.second && l1.first <= l2.second)
			return true;
		return false;
	}
	if (x <= 0 && y <= 0)
		return true;
	return false;
}

int main()
{
	ll x1, x2, x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Line L1 = {{x1, y1}, {x2, y2}};
	Line L2 = {{x3, y3}, {x4, y4}};

	if (check(L1, L2))
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}
