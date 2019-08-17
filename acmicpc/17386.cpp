#include <iostream>
using namespace std;
#define ll long long

struct Point {
	ll x, y;
};

struct Line {
	Point x, y;
};

int ccw(Point p1, Point p2, Point p3)
{
	ll t = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	t = t - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (t > 0)
		return 1;
	else if (t < 0)
		return -1;
	else
		return 0;
}

bool check(Line l1, Line l2)
{
	int x = ccw(l1.x, l1.y, l2.x) * ccw(l1.x, l1.y, l2.y);
	int y = ccw(l2.x, l2.y, l1.x) * ccw(l2.x, l2.y, l1.y);
	if (x < 0 && y < 0)
		return true;
	return false;
}

int main()
{
	ll x1, x2, x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Line L1 = {x1, y1, x2, y2};
	Line L2 = {x3, y3, x4, y4};

	if (check(L1, L2))
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}
