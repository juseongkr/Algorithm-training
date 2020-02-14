#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string map[MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
int n, m, sx, sy, ex, ey;
queue<pair<int, int>> que;

bool check(int mid)
{
	visit[sx][sy] = 1;
	que.push({sx, sy});

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || dist[nx][ny] < mid)
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny});
		}
	}
	return visit[ex][ey];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'V') {
				sx = i;
				sy = j;
			} else if (map[i][j] == 'J') {
				ex = i;
				ey = j;
			} else if (map[i][j] == '+') {
				que.push({i, j});
			}
		}
	}

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] || map[nx][ny] == '+')
				continue;

			dist[nx][ny] = dist[x][y] + 1;
			que.push({nx, ny});
		}
	}

	int l = 0, r = dist[sx][sy];
	while (l <= r) {
		int mid = (l+r)/2;
		memset(visit, 0, sizeof(visit));
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
