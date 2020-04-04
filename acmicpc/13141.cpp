#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 201
#define EDGE 20001
const int INF = 1e9+7;

int n, m, a, b, c;
int dist[MAX][MAX];
int x[EDGE], y[EDGE], z[EDGE];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (i != j)
				dist[i][j] = INF;

	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		x[i] = --a;
		y[i] = --b;
		z[i] = c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = INF;
	for (int i=0; i<n; ++i) {
		int ret = 0;
		for (int j=0; j<m; ++j) {
			int a = x[j];
			int b = y[j];
			int c = z[j];
			ret = max(ret, dist[i][a] + dist[i][b] + c);
		}
		ans = min(ans, ret);
	}
	cout << fixed << setprecision(1) << ans/2.0 << '\n';

	return 0;
}
