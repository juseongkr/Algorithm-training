#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int map[MAX][MAX], dist[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	if (map[0][0] == -1 || map[n-1][m-1] == -1) {
		cout << "-1\n";

		return 0;
	}

	for (int i=0; i<n; ++i)
		fill(dist[i], dist[i]+m, INF);

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({map[0][0], 0, 0});
	dist[0][0] = map[0][0];

	while (!que.empty()) {
		auto [z, x, y] = que.top();
		que.pop();
		
		if (x == n-1 && y == m-1) {
			cout << z << '\n';
			return 0;
		}

		if (visit[x][y])
			continue;
		visit[x][y] = 1;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || map[nx][ny] == -1)
				continue;

			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				que.push({dist[nx][ny], nx, ny});
			}
		}
	}
	cout << "-1\n";

	return 0;
}
