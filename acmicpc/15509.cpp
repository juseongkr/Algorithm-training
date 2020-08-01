#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000

int n, m, k, x, y;
bool dp[MAX+1];

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

	cin >> n >> m >> k;
	UnionFind u(n);
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		u.uni(x, y);
	}

	vector<int> ans;
	for (int i=1; i<=n; ++i)
		if (-u.p[i] > 0)
			ans.push_back(-u.p[i]);

	dp[0] = 1;
	for (int i=0; i<ans.size(); ++i) {
		int left = ans[i];
		for (int j=MAX-left; j>=0; j--) {
			if (dp[j])
				dp[j+left] = 1;
		}
	}

	if (dp[k])
		cout << "SAFE\n";
	else
		cout << "DOOMED\n";

	return 0;
}
