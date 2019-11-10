#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, x, y, p;

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
	
	cin >> n >> m;
	UnionFind u = UnionFind(n);
	for (int i=0; i<n; ++i) {
		cin >> p;
		u.p[i] = -p;
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		x--;
		y--;
		u.uni(x, y);
		cout << -u.p[u.find(x)] << '\n';
	}

	return 0;
}
