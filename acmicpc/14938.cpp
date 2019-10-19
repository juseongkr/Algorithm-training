#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, r, u, v, w;
int item[MAX];
int map[MAX][MAX];

int main()
{
	cin >> n >> m >> r;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				map[i][j] = INF;

	for (int i=1; i<=n; ++i)
		cin >> item[i];

	for (int i=0; i<r; ++i) {
		cin >> u >> v >> w;
		map[u][v] = map[v][u] = w;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				map[i][j] = min(map[i][k] + map[k][j], map[i][j]);

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		int cur = 0;
		for (int j=1; j<=n; ++j) {
			if (map[i][j] <= m)
				cur += item[j];
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';

	return 0;
}
