#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point {
public:
	long long x, y, idx;
	long long p, q;
	Point() : Point(0, 0, 1, 0) { }
	Point(long long x, long long y) : Point(x, y, 1, 0) { }
	Point(long long x, long long y, long long i) : Point(x, y, 1, 0) { idx = i; }
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

void scan(const vector<Point> &vec)
{
	vector<Point> v = vec;

	sort(v.begin(), v.end());

	for (int i=1; i<v.size(); ++i) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}

	sort(v.begin()+1, v.end());

	int sz = v.size()-1;
	for (int i=v.size()-1; i>1; i--) {
		if (ccw(v[0], v[sz], v[sz-1]) == 0)
			sz--;
		else
			break;
	}
	reverse(v.begin() + sz, v.end());
	for (int i=0; i<v.size(); ++i)
		cout << v[i].idx << " ";
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, x, y;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<Point> vec;
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			vec.push_back({x, y, i});
		}
		scan(vec);
	}

	return 0;
}
