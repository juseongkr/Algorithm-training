#include <iostream>
#include <queue>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char map[10][10];
int visit[10][10];
int sx, sy, ex, ey, ans;

int main()
{
	for (int i=0; i<10; ++i) {
		for (int j=0; j<10; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				sx = i;
				sy = j;
			} else if (map[i][j] == 'L') {
				map[i][j] = '.';
				ex = i;
				ey = j;
			}
		}
	}

	queue<pair<int, int>> que;
	visit[sx][sy] = 1;
	que.push({sx, sy});

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		if (x == ex && y == ey) {
			cout << visit[x][y] - 2 << '\n';
			return 0;
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10 || visit[nx][ny])
				continue;

			if (map[nx][ny] == '.') {
				visit[nx][ny] = visit[x][y] + 1;
				que.push({nx, ny});
			}
		}
	}
	cout << "0\n";

	return 0;
}
