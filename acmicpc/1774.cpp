#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <iomanip>
using namespace std;
typedef tuple<double, int, int> tdii;

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
		if (x != y) {
			p[x] += p[y];
			p[y] = x;
			return true;
		}
		return false;
	}
};

double dist(pair<int, int> a, pair<int, int> b)
{
	int x = a.first - b.first;
	int y = a.second - b.second;
	return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<pair<int, int>> vec;
	vector<tdii> pos;
	int n, m, x, y;

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		u.uni(x-1, y-1);
	}

	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			pos.push_back({dist(vec[i], vec[j]), i, j});

	sort(pos.begin(), pos.end());

	int cnt = 0;
	double ans = 0;
	for (int i=0; i<pos.size(); ++i) {
		auto [z, x, y] = pos[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}
	cout << fixed << setprecision(2) << ans << '\n';

	return 0;
}
