#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
pair<int, int> start, dest;
int board[300][300], visit[300][300], step[300][300];
int a[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int b[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int n, m;

void bfs(int x, int y)
{
	visit[x][y] = 1;
	que.push({x, y});

	while (!que.empty()) {
		auto t = que.front();
		que.pop();

		for (int i=0; i<8; ++i) {
			int next_x = t.first + a[i];
			int next_y = t.second + b[i];

			if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= m)
				continue;

			if (visit[next_x][next_y] == 0) {
				que.push({next_x, next_y});
				visit[next_x][next_y] = 1;
				step[next_x][next_y] = step[t.first][t.second] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &m);
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &dest.first, &dest.second);

		for (int i=0; i<m; ++i) {
			for (int j=0; j<m; ++j) {
				visit[i][j] = 0;
				step[i][j] = 0;
			}
		}
		
		bfs(start.first, start.second);

		printf("%d\n", step[dest.first][dest.second]);
	}

	return 0;
}
