#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 51
int n, m;
string map[MAX];
int visit[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int bfs(int a, int b)
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> que;
	int step = 0;
	visit[a][b] = 1;
	que.push({a, b});

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			step = max(step, visit[y][x]);

			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
				continue;

			if (visit[next_y][next_x] == 0 && map[next_y][next_x] == 'L') {
				que.push({next_y, next_x});
				visit[next_y][next_x] = visit[y][x] + 1;
			}
		}
	}
	return step-1;
}

int main()
{
	string s;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	int ans = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == 'L')
				ans = max(ans, bfs(i, j));

	cout << ans << '\n';

	return 0;
}
