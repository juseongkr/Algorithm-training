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

int p, w, c, v, x, y, z;
vector<tuple<int, int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> p >> w >> c >> v;
	UnionFind u = UnionFind(p);
	for (int i=0; i<w; ++i) {
		cin >> x >> y >> z;
		vec.push_back({-z, x, y});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<w; ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y) && u.find(c) == u.find(v)) {
			cout << -z << '\n';
			return 0;
		}
	}

	return 0;
}
