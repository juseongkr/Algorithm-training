#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
int map[501][501];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n, m, area, cnt = 0;

void bfs(int x, int y)
{
	que.push({x, y});
	map[x][y] = 0;

	while (!que.empty()) {
		auto t = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_x = t.first + a[i];
			int next_y = t.second + b[i];

			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
				continue;

			if (map[next_x][next_y] != 0) {
				map[next_x][next_y] = 0;
				que.push({next_x, next_y});
				area++;
			}
		}
	}
}

int main()
{
	int max_area = 0;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%d", &map[i][j]);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] != 0) {
				area = 1;
				bfs(i, j);
				cnt++;
				max_area = max(max_area, area);
			}
		}
	}
	printf("%d\n%d\n", cnt, max_area);

	return 0;
}
