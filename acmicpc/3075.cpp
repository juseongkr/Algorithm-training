#include <iostream>
using namespace std;
#define MAX 101
const long long INF = 1e18+7;

int T, n, p, q, x, y, z;
long long dist[MAX][MAX];
int meet[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> p >> q;
		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				dist[i][j] = (i == j) ? 0 : INF;

		for (int i=0; i<n; ++i) {
			cin >> meet[i];
			meet[i]--;
		}

		for (int i=0; i<q; ++i) {
			cin >> x >> y >> z;
			x--;
			y--;
			dist[x][y] = dist[y][x] = min(dist[x][y], z * 1LL);
		}

		for (int k=0; k<p; ++k)
			for (int i=0; i<p; ++i)
				for (int j=0; j<p; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		int pos = 0;
		long long ans = INF;
		for (int cur=0; cur<p; ++cur) {
			long long d = 0;
			bool flag = true;
			for (int j=0; j<n; ++j) {
				int next = meet[j];
				if (dist[cur][next] == INF) {
					flag = false;
					break;
				}
				d += dist[cur][next] * dist[cur][next];
			}

			if (flag && ans > d) {
				ans = d;
				pos = cur;
			}
		}
		cout << pos+1 << " " << ans << '\n';
	}

	return 0;
}
