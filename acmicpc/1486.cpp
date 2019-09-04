#include <iostream>
using namespace std;
#define MAX 26
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, t, d;
string map[MAX];
int mat[MAX*MAX][MAX*MAX];

int calc(int x, int y)
{
	if ('A' <= map[x][y] && map[x][y] <= 'Z')
		return map[x][y]-'A';
	return map[x][y]-'a'+26;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> t >> d;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n*m; ++i)
		for (int j=0; j<n*m; ++j)
			if (i != j)
				mat[i][j] = INF;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int cur = i*m+j;
			for (int k=0; k<4; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || y < 0 || x >= n || y >= m)
					continue;

				int next = x*m+y;
				int cost = calc(i, j) - calc(x, y);

				if (abs(cost) > t)
					continue;

				if (cost < 0)
					mat[cur][next] = cost*cost;
				else
					mat[cur][next] = 1;
			}
		}
	}

	for (int k=0; k<n*m; ++k)
		for (int i=0; i<n*m; ++i)
			for (int j=0; j<n*m; ++j)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	int ans = 0;
	for (int i=0; i<n*m; ++i)
		if (mat[0][i] + mat[i][0] <= d)
			ans = max(ans, calc(i/m, i%m));

	cout << ans << '\n';

	return 0;
}
