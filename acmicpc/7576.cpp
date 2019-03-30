#include <iostream>
#include <queue>
using namespace std;

queue<pair<int ,int>> que;
int tomato[1000][1000];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int m, n;

void bfs(void)
{
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_x = x + a[i];
			int next_y = y + b[i];
			
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
				continue;

			if (tomato[next_x][next_y] == 0) {
				que.push({next_x, next_y});
				tomato[next_x][next_y] = tomato[x][y] + 1;
			}
		}
	}

}

int main()
{
	int ans = 0;
	bool flag = false;

	cin >> m >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				que.push({i, j});
		}
	}

	bfs();

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (tomato[i][j] == 0)
				flag = true;
			ans = max(ans, tomato[i][j]);
		}
	}

	if (flag)
		cout << "-1\n";
	else
		cout << ans - 1 << '\n';

	return 0;
}
