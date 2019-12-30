#include <iostream>
#include <queue>
using namespace std;
#define MAX 701

const int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dyy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, m, ans;
bool visit[MAX][MAX];
int map[MAX][MAX];

void bfs(int u, int v)
{
	bool flag = true;
	queue<pair<int, int>> que;
	que.push({u, v});
	visit[u][v] = 1;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<8; ++i) {
			int nx = x + dxx[i];
			int ny = y + dyy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (map[x][y] < map[nx][ny]) {
				flag = false;

			} else if (map[x][y] == map[nx][ny] && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				que.push({nx, ny});
			}
		}
	}
	if (flag)
		ans++;
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
			if (map[i][j] && !visit[i][j])
				bfs(i, j);

	cout << ans << '\n';

	return 0;
}
