#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 501

class Point {
public:
	int x, y;
	Point() : x(0), y(0) { }
	Point(int a, int b) : x(a), y(b) { }
};

class Edge {
public:
	int u, v, c;
	Edge(int x, int y, int z) : u(x), v(y), c(z) { }
	bool operator<(const Edge &x) const { return c < x.c; }
};

int t, n, m, a, b;
int root[MAX];

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

int dist(const Point &a, const Point &b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		Point point[MAX];
		vector<Edge> v;

		cin >> n >> m;
		for (int i=0; i<m; ++i)
			cin >> point[i].x >> point[i].y;

		for (int i=0; i<m; ++i)
			for (int j=0; j<m; ++j)
				v.push_back({i, j, dist(point[i], point[j])});

		fill(root, root+MAX, -1);
		sort(v.begin(), v.end());

		int cnt = 0;
		for (int i=0; ; ++i) {
			if (uni(v[i].u, v[i].v)) {
				if (++cnt == m-n) {
					cout << fixed << setprecision(2) << sqrt(v[i].c) << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
