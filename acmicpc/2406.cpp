#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> ti3;

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

int n, m, x, y, z;
vector<ti3> vec;
vector<pair<int, int>> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		if (x != 1 && y != 1)
			u.uni(x, y);
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cin >> z;
			if (i < j && i != 1 && j != 1)
				vec.push_back({z, i, j});
		}
	}

	sort(vec.begin(), vec.end());

	int sum = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans.push_back({x, y});
			sum += z;
		}
	}

	cout << sum << " " << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << '\n';

	return 0;
}
