#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

int p[MAX];

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		p[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int q, n, k, u, v, m;

	cin >> q;
	for (int t=1; t<=q; ++t) {
		cin >> n >> k;
		for (int i=0; i<MAX; ++i)
			p[i] = i;

		for (int i=0; i<k; ++i) {
			cin >> u >> v;
			uni(u, v);
		}

		cin >> m;
		cout << "Scenario " << t << ":\n";
		for (int i=0; i<m; ++i) {
			cin >> u >> v;
			if (find(u) == find(v))
				cout << "1\n";
			else
				cout << "0\n";
		}
		cout << '\n';
	}

	return 0;
}
