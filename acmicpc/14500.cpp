#include <iostream>
using namespace std;

#define MAX 501
int map[501][501], visit[501][501];
int n, m, ans;
const int a[4] = {1, -1, 0, 0};
const int b[4] = {0, 0, 1, -1};

int dfs(int y, int x, int cnt)
{
	if (cnt == 4)
		return map[y][x];

	int ret = 0;
	for (int i=0; i<4; ++i) {
		int next_y = y + a[i];
		int next_x = x + b[i];

		if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
			continue;

		if (visit[next_y][next_x] == 0) {
			visit[next_y][next_x] = 1;
			ret = max(ret, map[y][x] + dfs(next_y, next_x, cnt+1));
			visit[next_y][next_x] = 0;
		}
	}
	return ret;
}

int solve(int y, int x)
{
	int ret = 0;
	if (y >= 1 && x >= 1 && x+1 < m)
		ret = max(ret, map[y][x] + map[y][x-1] + map[y-1][x] + map[y][x+1]);

	if (y >= 1 && y+1 < n && x+1 < m)
		ret = max(ret, map[y][x] + map[y-1][x] + map[y][x+1] + map[y+1][x]);

	if (y >= 0 && y+1 < n && x+1 < m)
		ret = max(ret, map[y][x] + map[y][x-1] + map[y+1][x] + map[y][x+1]);

	if (y >= 1 && y+1 < n && x >= 1)
		ret = max(ret, map[y][x] + map[y-1][x] + map[y][x-1] + map[y+1][x]);

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			visit[i][j] = 1;
			ans = max(ans, dfs(i, j, 1));
			ans = max(ans, solve(i, j));
			visit[i][j] = 0;
		}
	}

	cout << ans << '\n';

	return 0;
}
