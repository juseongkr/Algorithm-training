#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 20
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];

int bfs(int x, int y, int u, int v)
{
	int ret = 0;
	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			dist[i][j] = INF;

	queue<pair<int, int>> que;
	que.push({x, y});
	que.push({u, v});
	dist[x][y] = 0;
	dist[u][v] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (dist[nx][ny] == INF) {
				dist[nx][ny] = dist[x][y] + 1;
				que.push({nx, ny});
				if (map[nx][ny])
					ret = max(ret, dist[nx][ny]);
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%1d", &map[i][j]);

	int ans = INF;
	for (int i=0; i<n*m; ++i) {
		int x = i / m;
		int y = i % m;

		if (map[x][y])
			continue;

		for (int j=i+1; j<n*m; ++j) {
			int u = j / m;
			int v = j % m;

			if (map[u][v])
				continue;

			ans = min(ans, bfs(x, y, u, v));
		}
	}
	printf("%d\n", ans);

	return 0;
}
