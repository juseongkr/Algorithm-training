#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int map[MAX][MAX], s[MAX][MAX];
int dist[MAX][MAX];

int sum(int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, h, w, x1, x2, y1, y2;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	cin >> h >> w >> x1 >> y1 >> x2 >> y2;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + map[i][j];

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> que;
	que.push({x1, y1});
	dist[x1][y1] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx+h-1 > n || ny+w-1 > m)
				continue;

			if (sum(nx, ny, nx+h-1, ny+w-1) == 0) {
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					que.push({nx, ny});
				}
			}
		}
	}
	cout << dist[x2][y2] << '\n';

	return 0;
}
