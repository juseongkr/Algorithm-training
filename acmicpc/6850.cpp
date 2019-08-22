#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point {
public:
	long long x, y;
	long long p, q;
	Point() : Point(0, 0, 1, 0) { }
	Point(long long x, long long y) : Point(x, y, 1, 0) { }
	Point(long long x1, long long y1, long long p1, long long q1) : x(x1), y(y1), p(p1), q(q1) { }
	bool operator<(const Point& k) const
	{
		if (q * k.p != p * k.q)
			return q * k.p < p * k.q;
		if (y != k.y)
			return y < k.y;
		return x < k.x;
	}
};

int ccw(const Point &a, const Point &b, const Point &c)
{
	long long t = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (t > 0)
		return 1;
	else if (t < 0)
		return -1;
	else
		return 0;
}

vector<Point> scan(const vector<Point> &vec)
{
	vector<Point> v = vec;
	vector<Point> s;

	sort(v.begin(), v.end());

	for (int i=1; i<v.size(); ++i) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}

	sort(v.begin()+1, v.end());

	for (int i=0; i<v.size(); ++i) {
		while (s.size() >= 2 && ccw(s[s.size()-2], s[s.size()-1], v[i]) <= 0)
			s.pop_back();
		s.push_back(v[i]);
	}

	return s;
}

long long getArea(const vector<Point> &vec)
{
	vector<Point> v = vec;
	long long ans = 0;

	for (int i=0; i<v.size(); ++i) {
		ans += (long long)(v[i].x * v[(i+1)%v.size()].y);
		ans -= (long long)(v[i].y * v[(i+1)%v.size()].x);
	}
	return abs(ans)/100;
}

int main()
{
	vector<Point> v;
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		v.push_back({x, y});
	}
	auto s = scan(v);

	cout << getArea(s) << '\n';

	return 0;
}
