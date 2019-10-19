#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int map[MAX][MAX];

int main()
{
	int n, m, sx, sy;
	queue<pair<int, int>> que;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				que.push({i, j});
				map[i][j] = 2;
			}
		}
	}

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 1)
				continue;

			map[nx][ny] = map[x][y] + 1;
			que.push({nx, ny});
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j])
				cout << map[i][j]-2 << " ";
			else
				cout << "0 ";
		}
		cout << '\n';
	}

	return 0;
}
