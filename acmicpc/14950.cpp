#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

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
		if (p[x] < p[y]) {
			p[x] += p[y];
			p[y] = x;
		} else {
			p[y] += p[x];
			p[x] = y;
		}
		return true;
	}
};

vector<tuple<int, int, int>> vec;
int n, m, t, x, y, z;

int main()
{
	cin >> n >> m >> t;
	UnionFind u = UnionFind(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y});
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n-1)
				break;
		}
	}
	ans += (n-1) * (n-2) / 2 * t;
	cout << ans << '\n';

	return 0;
}
