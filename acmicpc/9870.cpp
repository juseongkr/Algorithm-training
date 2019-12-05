#include <iostream>
using namespace std;
#define MAX 201
const int INF = 1e9+7;

int map[MAX][MAX];
int n, m, k, q, x, y, z, cnt;
long long val;

int main()
{
	cin >> n >> m >> k >> q;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				map[i][j] = INF;

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		map[x][y] = min(map[x][y], z);
	}

	for (int p=1; p<=n; ++p)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				map[i][j] = min(map[i][j], map[i][p] + map[p][j]);

	for(int i=0; i<q; ++i) {
		cin >> x >> y;
		int ret = INF;
		for (int p=1; p<=k; ++p)
			ret = min(ret, map[x][p] + map[p][y]);

		if (ret != INF) {
			cnt++;
			val += ret;
		}
	}
	cout << cnt << '\n' << val << '\n';

	return 0;
}
