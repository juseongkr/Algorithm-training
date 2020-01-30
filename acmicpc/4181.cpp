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
		if (x != k.x)
			return x < k.x;
		return y < k.y;
	}
};

int n, x, y;
char z;
vector<Point> v;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y >> z;
		if (z == 'Y')
			v.push_back({x, y});
	}

	sort(v.begin(), v.end());

	for (int i=1; i<v.size(); ++i) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}

	sort(v.begin()+1, v.end());

	int i;
	for (i=v.size()-1; v[i].x == v[0].x; i--);
	
	reverse(v.begin()+i+1, v.end());

	cout << v.size() << '\n';
	for (int i=0; i<v.size(); ++i)
		cout << v[i].x << " " << v[i].y << '\n';

	return 0;
}
