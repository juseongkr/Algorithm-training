#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 101

class Point {
public:
	double x, y;
	Point() : x(.0), y(.0) { }
	Point(double a, double b) : x(a), y(b) { }
};

class Edge {
public:
	int u, v;
	double c;
	Edge(int x, int y, double z) : u(x), v(y), c(z) { }
	bool operator<(const Edge &x) const { return c < x.c; }
};

int n;
double x, y;
int root[MAX];
Point point[MAX];
vector<Edge> v;

int find(int n)
{
	if (root[n] < 0)
		return n;
	return root[n] = find(root[n]);
}

bool uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	root[y] = find(x);
	return true;
}

double dist(const Point &a, const Point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> point[i].x >> point[i].y;

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			v.push_back({i, j, dist(point[i], point[j])});

	fill(root, root+MAX, -1);
	sort(v.begin(), v.end());

	int cnt = 0;
	double ans = .0;
	for (int i=0; i<v.size(); ++i) {
		if (uni(v[i].u, v[i].v)) {
			ans += v[i].c;
			if (++cnt == n-1)
				break;
		}
	}

	cout << ans << '\n';

	return 0;
}
