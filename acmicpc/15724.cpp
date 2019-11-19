#include <iostream>
using namespace std;
#define MAX 1026

int map[MAX][MAX], sum[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, x, y, u, v, k;

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> map[i][j];
			sum[i][j] = map[i][j] + (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);
		}
	}

	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y >> u >> v;
		cout << sum[u][v] - (sum[x-1][v] + sum[u][y-1] - sum[x-1][y-1]) << '\n';
	}

	return 0;
}
