#include <iostream>
#include <vector>
using namespace std;
#define MAX 3001

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

int t, n, ans;
int x[MAX], y[MAX], r[MAX];

int dist(int x, int y, int a, int b)
{
	return (x-a) * (x-a) + (y-b) * (y-b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		UnionFind u = UnionFind(n);
		for (int i=0; i<n; ++i)
			cin >> x[i] >> y[i] >> r[i];

		ans = n;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (dist(x[i], y[i], x[j], y[j]) <= (r[i] + r[j]) * (r[i] + r[j]))
					if (u.uni(i, j))
						ans--;
		cout << ans << '\n';
	}

	return 0;
}
