#include <iostream>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, x, y, l, r;
int dist[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (i != j)
				dist[i][j] = INF;

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		dist[x][y] = dist[y][x] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = INF;
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) {
			int val = 0;
			for (int k=1; k<=n; ++k)
				val += min(dist[i][k], dist[k][j]);

			if (ans > val) {
				ans = val;
				l = i;
				r = j;
			}
		}
	}

	cout << l << " " << r << " " << ans * 2 << '\n';

	return 0;
}
