#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, ans;

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

	int getSize(int x)
	{
		return -p[find(x)];
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	UnionFind uf(n);
	bool flag = false;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		if (!uf.uni(x, y) && !flag) {
			ans = i+1;
			flag = true;
		}
	}

	cout << ans << '\n';

	return 0;
}
