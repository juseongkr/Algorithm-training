#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

queue<tuple<int, int, int>> que, next_que;
int map[101][101], visit[101][101];
int n, num, len, dis = INT_MAX;
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};

void dfs(int x, int y, int c)
{
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
			continue;

		if (map[next_x][next_y] == 1 && visit[next_x][next_y] == 0) {
			que.push({next_x, next_y, c});
			visit[next_x][next_y] = 1;
			dfs(next_x, next_y, c);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%d", &map[i][j]);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				num++;
				visit[i][j] = 1;
				que.push({i, j, num});
				dfs(i, j, num);
			}
		}
	}

	while (!que.empty()) {
		auto [x, y, c] = que.front();
		que.pop();

		next_que = que;
		while (!next_que.empty()) {
			auto [next_x, next_y, next_c] = next_que.front();
			next_que.pop();

			if (c != next_c) {
				len = abs(next_x - x) + abs(next_y - y);
				dis = min(dis, len);
			}
		}
	}

	printf("%d\n", dis-1);

	return 0;
}
