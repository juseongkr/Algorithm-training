#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 11
const int INF = 1e9+7;
const int dx1[8] = {2, 1, -1, -2,  -2, -1, 1, 2};
const int dy1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dx2[4] = {1, 1, -1, -1};
const int dy2[4] = {1, -1, -1, 1};
const int dx3[4] = {1, -1, 0, 0};
const int dy3[4] = {0, 0, 1, -1};

int n, sx, sy;
int map[MAX][MAX];
int dist[MAX][MAX][MAX*MAX][3];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (--map[i][j] == 0) {
				sx = i;
				sy = j;
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int, int>> que;
	for (int i=0; i<3; ++i) {
		dist[sx][sy][0][i] = 0;
		que.push({sx, sy, 0, i});
	}

	int ans = INF;
	while (!que.empty()) {
		auto [x, y, k, c] = que.front();
		que.pop();

		if (k == n*n-1)
			ans = min(ans, dist[x][y][k][c]);

		if (c == 1) {
			for (int i=0; i<8; ++i) {
				int nx = x + dx1[i];
				int ny = y + dy1[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				int nk = k;
				if (map[nx][ny] == k+1)
					nk = k+1;

				if (dist[nx][ny][nk][c] == -1) {
					dist[nx][ny][nk][c] = dist[x][y][k][c] + 1;
					que.push({nx, ny, nk, c});
				}
			}

		} else if (c == 2) {
			for (int i=0; i<4; ++i) {
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx2[i];
					ny += dy2[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						break;

					int nk = k;
					if (map[nx][ny] == k+1)
						nk = k+1;

					if (dist[nx][ny][nk][c] == -1) {
						dist[nx][ny][nk][c] = dist[x][y][k][c] + 1;
						que.push({nx, ny, nk, c});
					}
				}
			}
		} else {
			for (int i=0; i<4; ++i) {
				int nx = x;
				int ny = y;
				while (1) {
					nx += dx3[i];
					ny += dy3[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						break;

					int nk = k;
					if (map[nx][ny] == k+1)
						nk = k+1;

					if (dist[nx][ny][nk][c] == -1) {
						dist[nx][ny][nk][c] = dist[x][y][k][c] + 1;
						que.push({nx, ny, nk, c});
					}
				}
			}
		}

		for (int i=0; i<3; ++i) {
			if (i != c) {
				if (dist[x][y][k][i] == -1) {
					dist[x][y][k][i] = dist[x][y][k][c] + 1;
					que.push({x, y, k, i});
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
