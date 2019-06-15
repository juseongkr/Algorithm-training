#include <iostream>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
#define MAX 301
typedef tuple<int, int, int> ti3;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
priority_queue<ti3, vector<ti3>, greater<ti3>> que;
int map[MAX][MAX], visit[MAX][MAX];
int n, m, ans;

void dfs(int v, int y, int x)
{
	visit[y][x] = 1;
	for (int i=0; i<4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n)
			continue;

		if (visit[next_y][next_x])
			continue;

		visit[next_y][next_x] = 1;
		if (map[next_y][next_x] > v) {
			que.push({map[next_y][next_x], next_y, next_x});
		} else {
			dfs(v, next_y, next_x);
			ans += (v - map[next_y][next_x]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (i == 0 || j == 0 || i == m-1 || j == n-1)
				que.push({map[i][j], i, j});
		}
	}

	while (!que.empty()) {
		auto [v, y, x] = que.top();
		que.pop();
		dfs(v, y, x);
	}

	cout << ans << '\n';

	return 0;
}
