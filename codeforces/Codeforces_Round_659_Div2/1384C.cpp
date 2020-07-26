#include <iostream>
#include <vector>
using namespace std;

int T, n;
string a, b;

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
	while(T--) {
		cin >> n >> a >> b;
		if (a == b) {
			cout << "0\n";
			continue;
		}

		UnionFind u(26);
		int ans = 0;
		bool flag = false;
		for (int i=0; i<n; ++i) {
			if (b[i] > a[i]) {
				if (u.uni(a[i]-'a', b[i]-'a'))
					ans++;
			} else if (b[i] < a[i]) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
