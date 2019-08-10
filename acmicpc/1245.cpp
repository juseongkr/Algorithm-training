#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

const int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
int map[MAX][MAX], visit[MAX][MAX];
int n, m, ans;

void bfs(int x, int y)
{
	queue<pair<int, int>> que;
	que.push({x, y});
	visit[x][y] = 1;

	bool flag = true;
	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
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
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!visit[i][j] && map[i][j])
				bfs(i, j);
	cout << ans << '\n';

	return 0;
}
