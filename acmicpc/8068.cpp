#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 102
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int INF = 1e9+7;
typedef tuple<int, int, int> ti;

int n, m;
int map[MAX][MAX], height[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	n += 2;
	m += 2;

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			height[i][j] = INF;

	priority_queue<ti, vector<ti>, greater<ti>> que;
	que.push({0, 0, 0});
	height[0][0] = 0;

	while (!que.empty()) {
		auto [d, x, y] = que.top();
		que.pop();

		if (visit[x][y])
			continue;
		visit[x][y] = 1;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			
			int nd = max(height[x][y], map[nx][ny]);
			if (height[nx][ny] > nd) {
				height[nx][ny] = nd;
				que.push({nd, nx, ny});
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans += height[i][j] - map[i][j];
	cout << ans << '\n';

	return 0;
}
