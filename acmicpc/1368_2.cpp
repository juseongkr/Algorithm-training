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
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

int n, x;
vector<tuple<int, int, int>> vec;

int main()
{
	cin >> n;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> x;
		vec.push_back({x, i, n});
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> x;
			vec.push_back({x, i, j});
		}
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y))
			ans += z;
	}
	cout << ans << '\n';

	return 0;
}
