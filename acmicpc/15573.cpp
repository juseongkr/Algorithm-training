#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
priority_queue<tp, vector<tp>, greater<tp>> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (i == 0 || j == 0 || j == m-1) {
				que.push({map[i][j], i, j});
				visit[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while (k--) {
		auto [cost, x, y] = que.top();
		que.pop();

		ans = max(ans, map[x][y]);
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny])
				continue;

			visit[nx][ny] = 1;
			que.push({map[nx][ny], nx, ny});
		}
	}

	cout << ans << '\n';

	return 0;
}
