#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <tuple>
#include <set>
using namespace std;
#define MAX 1001
typedef tuple<double, int, int> tp;

int n, e, p, u, v;
double map[MAX][MAX], x[MAX], y[MAX];
vector<tp> vec;

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(n+1, -1); }
	int find(int x)
	{
		if (p[x] < 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

inline double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> e >> p;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	UnionFind uf(n);
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			map[i][j] = dist(x[i], y[i], x[j], y[j]);

	for (int i=0; i<p; ++i) {
		cin >> u >> v;
		u--;
		v--;
		if (u > v)
			swap(u, v);
		map[u][v] = 0;
	}

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			vec.push_back({map[i][j], i, j});

	for (int i=0; i<e; ++i)
		vec.push_back({0, i, n});

	sort(vec.begin(), vec.end());

	int cnt = 0;
	double ans = 0;
	for (int i=0; cnt<n; ++i) {
		auto [z, x, y] = vec[i];
		if (uf.uni(x, y)) {
			ans += z;
			cnt++;
		}
	}

	cout << fixed << setprecision(3) << ans << '\n';

	return 0;
}
