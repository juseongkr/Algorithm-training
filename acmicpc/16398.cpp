#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tiii;

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

	vector<tiii> vec;
	int n, k;

	cin >> n;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> k;
			vec.push_back({k, i, j});
		}
	}

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=0; i<vec.size(); ++i) {
		auto [z, x, y] = vec[i];
		if (u.uni(x, y))
			ans += z;
	}
	cout << ans << '\n';

	return 0;
}
