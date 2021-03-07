#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 51
const int INF = 1e9+7;
typedef pair<int, int> pi;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, water[MAX][MAX], dist[MAX][MAX];
string map[MAX];
pi start, dest;
queue<pi> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	memset(water, -1, sizeof(water));
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'D') {
				dest = {i, j};
			} else if (map[i][j] == 'S') {
				start = {i, j};
			} else if (map[i][j] == '*') {
				que.push({i, j});
				water[i][j] = 0;
			}
		}
	}

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'X' || map[nx][ny] == 'D' || water[nx][ny] != -1)
				continue;

			water[nx][ny] = water[x][y] + 1;
			que.push({nx, ny});
		}
	}

	memset(dist, -1, sizeof(dist));
	que.push({start.first, start.second});
	dist[start.first][start.second] = 0;

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1 || map[nx][ny] == 'X')
				continue;

			if (water[nx][ny] != -1 && water[nx][ny] <= dist[x][y] + 1)
				continue;

			dist[nx][ny] = dist[x][y] + 1;
			que.push({nx, ny});
		}
	}

	if (dist[dest.first][dest.second] == -1)
		cout << "KAKTUS\n";
	else
		cout << dist[dest.first][dest.second] << '\n';

	return 0;
}
