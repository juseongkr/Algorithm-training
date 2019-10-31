#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int map[MAX][MAX];
int dist[MAX][MAX][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, sx, sy, ex, ey;

	cin >> n >> m >> sx >> sy >> ex >> ey;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	queue<tuple<int, int, int>> que;
	que.push({sx, sy, 1});
	dist[sx][sy][1] = 1;

	while (!que.empty()) {
		auto [x, y, flag] = que.front();
		que.pop();

		if (x == ex && y == ey) {
			cout << dist[x][y][flag]-1 << '\n';
			return 0;
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;

			if (map[nx][ny] && flag) {
				dist[nx][ny][flag-1] = dist[x][y][flag] + 1;
				que.push({nx, ny, flag-1});
			}

			if (!map[nx][ny] && !dist[nx][ny][flag]) {
				dist[nx][ny][flag] = dist[x][y][flag] + 1;
				que.push({nx, ny, flag});
			}
		}
	}
	cout << "-1\n";

	return 0;
}
