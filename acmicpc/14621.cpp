#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 1001
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

bool type[MAX];

int main()
{
	vector<ti3> vec;
	int n, m, x, y, z;
	char c;

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=1; i<=n; ++i) {
		cin >> c;
		if (c == 'M')
			type[i] = 1;
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		if (type[x] != type[y])
			vec.push_back({z, x, y});
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
