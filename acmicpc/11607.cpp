#include <iostream>
#include <queue>
using namespace std;
#define MAX 501
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
int dist[MAX][MAX];
string map[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i)
		fill(dist[i], dist[i]+m, INF);
	
	queue<pair<int, int>> que;
	que.push({0, 0});
	dist[0][0] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i] * (map[x][y]-'0');
			int ny = y + dy[i] * (map[x][y]-'0');

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				que.push({nx, ny});
			}
		}
	}

	if (dist[n-1][m-1] == INF)
		cout << "IMPOSSIBLE\n";
	else
		cout << dist[n-1][m-1] << '\n';

	return 0;
}
