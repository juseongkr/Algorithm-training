#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int>> que;
int tomato[101][101][101];
int a[6] = {1, 0, 0, -1, 0, 0};
int b[6] = {0, 1, 0, 0, -1, 0};
int c[6] = {0, 0, 1, 0, 0, -1};
int n, m, h, ans;
bool flag = false;

void bfs()
{
	while (!que.empty()) {
		auto [z, y, x] = que.front();
		que.pop();

		for (int i=0; i<6; ++i) {
			int next_z = z + a[i];
			int next_y = y + b[i];
			int next_x = x + c[i];

			if (next_z < 0 || next_y < 0 || next_x < 0 || next_z >= h || next_y >= m || next_x >= n)
				continue;

			if (tomato[next_z][next_y][next_x] == 0) {
				tomato[next_z][next_y][next_x] = tomato[z][y][x] + 1;
				que.push({next_z, next_y, next_x});
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &h);
	for (int k=0; k<h; ++k) {
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				scanf("%d", &tomato[k][i][j]);
				if (tomato[k][i][j] == 1)
					que.push({k, i, j});
			}
		}
	}

	bfs();

	for (int k=0; k<h; ++k) {
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (tomato[k][i][j] == 0)
					flag = true;
				ans = max(ans, tomato[k][i][j]);
			}
		}
	}

	if (flag)
		printf("-1\n");
	else
		printf("%d\n", ans - 1);

	return 0;
}
