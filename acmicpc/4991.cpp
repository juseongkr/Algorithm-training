#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 21
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s;
int n, m;
int map[MAX][MAX];
int dist[MAX][MAX][(1 << 11)];

int main()
{
	while (1) {
		queue<tuple<int, int, int>> que;
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));
		bool flag = false;
		int num = 0;

		cin >> m >> n;
		if (n == 0 && m == 0)
			break;

		for (int i=0; i<n; ++i) {
			cin >> s;
			for (int j=0; j<m; ++j) {
				if (s[j] == '*')
					map[i][j] = ++num;
				else if (s[j] == 'o')
					que.push({0, i, j});
				else if (s[j] == 'x')
					map[i][j] = INF;
			}
		}

		while (!que.empty()) {
			auto [z, x, y] = que.front();
			que.pop();

			if (z == (1 << num)-1) {
				cout << dist[x][y][z] << '\n';
				flag = true;
				break;
			}

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z | (1 << (map[nx][ny]-1));

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == INF)
					continue;

				if (map[nx][ny] > 0) {
					if (dist[nx][ny][nz])
						continue;
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					que.push({nz, nx, ny});
				}

				if (map[nx][ny] == 0) {
					if (dist[nx][ny][z])
						continue;
					dist[nx][ny][z] = dist[x][y][z] + 1;
					que.push({z, nx, ny});
				}
			}
		}

		if (!flag)
			cout << "-1\n";
	}

	return 0;
}
