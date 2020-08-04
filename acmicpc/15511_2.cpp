#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

int n, m, x, y;
int group[MAX];

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

	cin >> n >> m;
	UnionFind u(n);
	fill(group, group+n+1, -1);
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		x = u.find(x);
		y = u.find(y);

		if (x == y) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}

		if (group[x] == -1 && group[y] == -1) {
			group[x] = y;
			group[y] = x;
		} else if (group[x] == -1 && group[y] != -1) {
			u.uni(x, group[y]);
		} else if (group[x] != -1 && group[y] == -1) {
			u.uni(group[x], y);
		} else {
			u.uni(x, group[y]);
			u.uni(group[x], y);
		}
	}
	cout << "POSSIBLE\n";

	return 0;
}
