#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, x, y;

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

	cin >> n;
	UnionFind uf(n);
	for (int i=0; i<n-2; ++i) {
		cin >> x >> y;
		uf.uni(x, y);
	}

	set<int> ans;
	for (int i=1; i<=n; ++i)
		ans.insert(uf.find(i));

	auto it = ans.begin();

	cout << *it++ << " " << *it << '\n';

	return 0;
}
