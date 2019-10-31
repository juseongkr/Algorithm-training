#include <iostream>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int map[MAX][MAX], num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n, m, x, y, z, k, s;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (i != j)
					map[i][j] = INF;

		for (int i=0; i<m; ++i) {
			cin >> x >> y >> z;
			map[x][y] = map[y][x] = z;
		}

		cin >> k;
		for (int i=0; i<k; ++i)
			cin >> num[i];

		for (int k=1; k<=n; ++k)
			for (int i=1; i<=n; ++i)
				for (int j=1; j<=n; ++j)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

		int mi = INF, ans = 0;
		for (int i=1; i<=n; ++i) {
			int sum = 0;
			for (int j=0; j<k; ++j)
				sum += map[i][num[j]];

			if (mi > sum) {
				mi = sum;
				ans = i;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
