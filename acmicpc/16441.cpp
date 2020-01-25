#include <iostream>
#include <queue>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
string map[MAX];
bool visit[MAX][MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	queue<pair<int, int>> que;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'W') {
				visit[i][j] = 1;
				que.push({i, j});
			}
		}
	}

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#')
				continue;

			if (map[nx][ny] == '+') {
				while (1) {
					int nxx = nx + dx[i];
					int nyy = ny + dy[i];
					if (map[nxx][nyy] == '#' || map[nx][ny] == '.' || map[nx][ny] == 'W')
						break;
					nx += dx[i];
					ny += dy[i];
				}
			}

			if (!visit[nx][ny]) {
				visit[nx][ny] = 1;
				que.push({nx, ny});
			}
		}
	}
	
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '.' && !visit[i][j])
				cout << "P";
			else
				cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}
