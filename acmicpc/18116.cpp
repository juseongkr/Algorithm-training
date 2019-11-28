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
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int q, x, y;
	char c;

	cin >> q;
	UnionFind u = UnionFind(1000001);
	while (q--) {
		cin >> c >> x;
		if (c == 'I') {
			cin >> y;
			u.uni(x, y);
		} else {
			cout << -u.p[u.find(x)] << '\n';
		}
	}

	return 0;
}
