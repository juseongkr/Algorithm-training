#include <iostream>
#include <vector>
using namespace std;

int T, n, m, a, b;

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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		UnionFind u(n);
		for (int i=0; i<m; ++i) {
			cin >> a >> b;
			u.uni(a, b);
		}

		if (n == m+1 && -u.p[u.find(1)] == n)
			cout << "tree\n";
		else
			cout << "graph\n";

	}

	return 0;
}
