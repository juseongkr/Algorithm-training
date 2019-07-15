#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 1001

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int map[MAX][MAX], visit[MAX][MAX][11][2];
int n, m, k;

int bfs()
{
	queue<tuple<int, int, int, int>> que;
	visit[0][0][0][0] = 1;
	que.push({0, 0, 0, 0});

	while (!que.empty()) {
		auto [y, x, z, r] = que.front();
		que.pop();

		if (y == n-1 && x == m-1)
			return visit[y][x][z][r];

		for (int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (!map[ny][nx] && !visit[ny][nx][z][1-r]) {
				visit[ny][nx][z][1-r] = visit[y][x][z][r] + 1;
				que.push({ny, nx, z, 1-r});
			}
			if (r == 0 && z+1 <= k && map[ny][nx] && !visit[ny][nx][z+1][1-r]) {
				visit[ny][nx][z+1][1-r] = visit[y][x][z][r] + 1;
				que.push({ny, nx, z+1, 1-r});
			}
		}
		if (!visit[y][x][z][1-r]) {
			visit[y][x][z][1-r] = visit[y][x][z][r] + 1;
			que.push({y, x, z, 1-r});
		}
	}
	return -1;
}

int main()
{
	string s;

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j)
			map[i][j] = s[j]-'0';
	}

	cout << bfs() << '\n';

	return 0;
}
