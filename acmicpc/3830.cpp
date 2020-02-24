#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

char c;
int n, m, x, y, z;
long long dist[MAX];
int p[MAX];

int find(int x)
{
	if (p[x] == x)
		return x;
	int ret = find(p[x]);
	dist[x] += dist[p[x]];
	return p[x] = ret;
}

void uni(int x, int y, int z)
{
	int u = find(x);
	int v = find(y);
	if (u != v) {
		p[v] = u;
		dist[v] = dist[x] - dist[y] + z;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i=1; i<=n; ++i) {
			dist[i] = 0;
			p[i] = i;
		}

		for (int i=0; i<m; ++i) {
			cin >> c;
			if (c == '!') {
				cin >> x >> y >> z;
				uni(x, y, z);
			} else {
				cin >> x >> y;
				if (find(x) == find(y))
					cout << dist[y] - dist[x] << '\n';
				else
					cout << "UNKNOWN\n";
			}
		}
	}

	return 0;
}
