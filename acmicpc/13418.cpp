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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<tuple<int, int, int>> vec;
	int n, m, x, y, z;

	cin >> n >> m;
	for (int i=0; i<=m; ++i) {
		cin >> x >> y >> z;
		vec.push_back({z, x, y});
	}

	sort(vec.begin(), vec.end());

	int bad = 0, good = 0;
	UnionFind u = UnionFind(n);
	for (int i=0; i<=m; ++i) {
		auto [c, a, b] = vec[i];
		if (u.uni(a, b))
			good += !c;
	}

	u = UnionFind(n);
	for (int i=m; i>=0; i--) {
		auto [c, a, b] = vec[i];
		if (u.uni(a, b))
			bad += !c;
	}

	cout << good * good - bad * bad<< '\n';

	return 0;
}
