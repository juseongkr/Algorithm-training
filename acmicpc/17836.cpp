#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int> tp;

int n, m, t, sx, sy;
bool visit[MAX][MAX];
int map[MAX][MAX];

int bfs(int x, int y, int ex, int ey)
{
	memset(visit, 0, sizeof(visit));
	queue<tp> que;
	que.push({x, y, 0});
	visit[x][y] = 1;

	while (!que.empty()) {
		auto [x, y, dep] = que.front();
		que.pop();

		if (x == ex && y == ey)
			return dep;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || map[nx][ny] == 1)
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, dep+1});
		}
	}

	return INF;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	}
	
	int x = bfs(0, 0, n-1, m-1);
	int y = bfs(0, 0, sx, sy) + abs(n-1-sx) + abs(m-1-sy);
	
	if (x <= t && y <= t)
		cout << min(x, y) << '\n';
	else if (x <= t)
		cout << x << '\n';
	else if (y <= t)
		cout << y << '\n';
	else
		cout << "Fail\n";
	
	return 0;
}
