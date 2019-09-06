#include <iostream>
using namespace std;
#define MAX 101
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, m, ans;
char map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y)
{
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (!visit[nx][ny] && map[nx][ny] == '#') {
			visit[nx][ny] = 1;
			map[nx][ny] = '.';
			dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '#') {
				visit[i][j] = 1;
				map[i][j] = '.';
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
