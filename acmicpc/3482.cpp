#include <iostream>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int T, n, m, ans, X, Y;
bool visit[MAX][MAX];
string map[MAX];

void dfs(int x, int y, int k)
{
	if (ans < k) {
		ans = k;
		X = x;
		Y = y;
	}

	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (!visit[nx][ny])
			dfs(nx, ny, k+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> m >> n;
		X = 0, Y = 0, ans = 0;
		for (int i=0; i<n; ++i)
			cin >> map[i];

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] != '.')
					visit[i][j] = 1;
				else
					visit[i][j] = 0;
			}
		}

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (!visit[i][j])
					dfs(i, j, 0);

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] != '.')
					visit[i][j] = 1;
				else
					visit[i][j] = 0;
			}
		}

		dfs(X, Y, 0);

		cout << "Maximum rope length is " << ans << ".\n";
	}

	return 0;
}
