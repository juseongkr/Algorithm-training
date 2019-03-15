#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int map[101][101];
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, 1, 0, -1};
int n, m;

void bfs(void)
{
	queue<pair<int, int>> que;
	que.push({0, 0});

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_x = x + a[i];
			int next_y = y + b[i];

			if (next_x < 0 || next_y < 0 || next_x > n - 1 || next_y > m - 1)
				continue;

			if (map[next_x][next_y] == 1) {
				que.push({next_x, next_y});
				map[next_x][next_y] = map[x][y] + 1;
			}
		}
	}
}

int main()
{
	memset(map, 0, sizeof(map));
	scanf("%d %d", &n, &m);
	
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%1d", &map[i][j]);
	
	bfs();
	printf("%d\n", map[n-1][m-1]);

	return 0;
}
