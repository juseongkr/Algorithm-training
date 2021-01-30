#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 51
const int STEP = 1e4;
typedef tuple<int, int, int> tp;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s;
int map[MAX][MAX], dist[MAX][MAX];
int n, m, sx, sy, ex, ey;

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j) {
			if (s[j] == 'S') {
				sx = i;
				sy = j;
				map[i][j] = -1;
			} else if (s[j] == 'F') {
				ex = i;
				ey = j;
				map[i][j] = -1;
			} else if (s[j] == 'g') {
				map[i][j] = STEP;
				for (int d=0; d<4; ++d) {
					int nx = i + dx[d];
					int ny = j + dy[d];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;

					if (!map[nx][ny])
						map[nx][ny] = 1;
				}

			}
		}
	}


	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, sx, sy});

	map[sx][sy] = map[ex][ey] = 0;
	memset(dist, -1, sizeof(dist));
	while (!que.empty()) {
		auto [z, x, y] = que.top();
		que.pop();

		if (~dist[x][y])
			continue;
		dist[x][y] = z;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || ~dist[nx][ny])
				continue;

			que.push({map[nx][ny] + z, nx, ny});
		}
	}

	cout << dist[ex][ey] / STEP << " " << dist[ex][ey] % STEP << '\n';

	return 0;
}
