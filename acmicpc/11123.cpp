#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int T, n, m;
string map[MAX];
bool visit[MAX][MAX];

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || map[nx][ny] == '.')
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i=0; i<n; ++i)
			cin >> map[i];

		int cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] == '#' && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
