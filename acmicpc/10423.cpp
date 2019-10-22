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
		if (x != y) {
			p[x] += p[y];
			p[y] = x;
			return true;
		}
		return false;
	}
};

int main()
{
	int n, m, k, x, y, z, root;

	cin >> n >> m >> k >> root;
	UnionFind u = UnionFind(n);
	for (int i=0; i<k-1; ++i) {
		cin >> z;
		u.uni(root-1, z-1);
	}

	vector<tuple<int, int, int>> vec;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x-1, y-1});
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<m; ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n)
				break;
		}
	}
	cout << ans << '\n';

	return 0;
}
