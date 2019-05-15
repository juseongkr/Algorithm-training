#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 1001
queue<tuple<int, int, int>> que;
int map[MAX][MAX];
int step[MAX][MAX][2];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m;

int bfs()
{
	que.push({0, 0, 1});
	step[0][0][1] = 1;
	while (!que.empty()) {
		auto [y, x, flag] = que.front();
		que.pop();

		if (y == n-1 && x == m-1)
			return step[y][x][flag];
		
		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
				continue;

			if (map[next_y][next_x] && flag) {
				que.push({next_y, next_x, flag-1});
				step[next_y][next_x][flag-1] = step[y][x][flag] + 1;
			}

			if (!map[next_y][next_x] && !step[next_y][next_x][flag]) {
				que.push({next_y, next_x, flag});
				step[next_y][next_x][flag] = step[y][x][flag] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	string s;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j)
			map[i][j] = (s[j]-'0');
	}

	cout << bfs() << '\n';

	return 0;
}
