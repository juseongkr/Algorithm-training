#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
int map[301][301];
int adj[301][301];
int visit[301][301];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n, m, cnt, year;
bool flag = false;

void dfs(int y, int x)
{
	visit[y][x] = 1;
	for (int i=0; i<4; ++i) {
		int next_y = y + a[i];
		int next_x = x + b[i];

		if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
			continue;

		if (map[next_y][next_x] && !visit[next_y][next_x]) {
			visit[next_y][next_x] = 1;
			dfs(next_y, next_x);
		}
	}
}

void bfs()
{
	while (!que.empty()) {
		auto t = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = t.first + a[i];
			int next_x = t.second + b[i];

			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
				continue;

			if (map[next_y][next_x] == 0)
				adj[t.first][t.second]++;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j])
				que.push({i, j});
		}
	}

	while (!que.empty()) {
		memset(visit, 0, sizeof(visit));
		memset(adj, 0, sizeof(adj));
		cnt = 0;
		year++;
		bfs();
	
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] >= adj[i][j])
					map[i][j] -= adj[i][j];
				else
					map[i][j] = 0;
				if (map[i][j])
					que.push({i, j});
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			flag = true;
			break;
		}
	}

	if (flag)
		printf("%d\n", year);
	else
		printf("0\n");

	return 0;
}
