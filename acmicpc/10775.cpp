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
	int g, p, t, ans = 0;

	cin >> g >> p;
	UnionFind u = UnionFind(g);
	for (int i=0; i<p; ++i) {
		cin >> t;
		int parent = u.find(t);
		if (parent > 0) {
			ans++;
			u.uni(parent-1, parent);
		} else {
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
