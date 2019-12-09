#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 2001
typedef tuple<int, int, int> ti3;

int x[MAX], y[MAX];

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

int main()
{
	int n, c;
	vector<ti3> vec;

	cin >> n >> c;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		for (int j=0; j<i; ++j) {
			int dist = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
			if (dist >= c)
				vec.push_back({dist, i, j});

		}
	}

	sort(vec.begin(), vec.end());

	int ans = 0, cnt = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == n-1) {
				cout << ans << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";

	return 0;
}
