#include <iostream>
#include <vector>
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

int main()
{
	int q, n, t;

	cin >> q;
	while (q--) {
		cin >> n;
		UnionFind u = UnionFind(n);
		for (int i=1; i<=n; ++i) {
			cin >> t;
			u.uni(i, t);
		}

		for (int i=1; i<=n; ++i)
			cout << -u.p[u.find(i)] << " ";
		cout << '\n';
	}

	return 0;
}
