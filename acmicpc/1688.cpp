#include <iostream>
#include <vector>
using namespace std;

struct Point {
	long long x, y;
};

struct Line {
	Point x, y;
};

vector<Point> v;
int n, x, y;

int ccw(Point p1, Point p2, Point p3)
{
	long long t = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	t -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	if (t < 0)
		return -1;
	else if (t > 0)
		return 1;
	else
		return 0;
}

bool cross(Line a, Line b)
{
	int x = ccw(a.x, a.y, b.x) * ccw(a.x, a.y, b.y);
	int y = ccw(b.x, b.y, a.x) * ccw(b.x, b.y, a.y);
	if (x <= 0 && y <= 0)
		return true;
	return false;
}

int solve(Point p)
{
	for (int i=0; i<n; ++i) {
		int t = ccw(v[i], v[i+1], p);
		if (t == 0) {
			auto mi = min(v[i].x, v[i+1].x);
			auto mx = max(v[i].x, v[i+1].x);
			if (mi <= p.x && p.x <= mx)
				return 1;
		}
	}

	Point q = {1, (int)1e9+7};
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		Line l = {p, q};
		cnt += cross(l, Line{v[i], v[i+1]});
	}
	if (cnt % 2 == 0)
		return 0;
	return 1;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		v.push_back({x, y});
	}
	v.push_back(v[0]);

	for (int i=0; i<3; ++i) {
		cin >> x >> y;
		cout << solve({x, y}) << '\n';
	}

	return 0;
}
