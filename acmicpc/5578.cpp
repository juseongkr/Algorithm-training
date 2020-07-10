#include <iostream>
#include <cstring>
using namespace std;
#define MAX 91
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, ans;
bool map[MAX][MAX];

int dfs(int x, int y)
{
	int cnt = 1;
	map[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || !map[nx][ny])
			continue;

		cnt = max(cnt, dfs(nx, ny) + 1);
	}
	map[x][y] = 1;
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j])
				ans = max(ans, dfs(i, j));

	cout << ans << '\n';

	return 0;
}
