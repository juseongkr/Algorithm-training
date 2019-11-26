#include <iostream>
#include <vector>
#include <queue>
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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, c, h, k, x, y;

	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		u.uni(x, y);
	}
	cin >> c >> h >> k;

	priority_queue<int> que;
	for (int i=1; i<=n; ++i) {
		if (u.p[i] > 0)
			continue;

		if (u.find(i) != u.find(c) && u.find(i) != u.find(h))
			que.push(-u.p[u.find(i)]);
	}

	int ans = -u.p[u.find(c)];
	for (int i=0; i<k; ++i) {
		if (que.empty())
			break;
		ans += que.top();
		que.pop();
	}

	cout << ans << '\n';

	return 0;
}
