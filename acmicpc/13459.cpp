#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 11

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n, m, ans, cnt;
char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
pair<int, int> red, blue;

bool bfs()
{
	queue<tuple<int, int, int, int>> que;
	que.push({red.first, red.second, blue.first, blue.second});
	visit[red.first][red.second][blue.first][blue.second] = true;

	while (!que.empty()) {
		int len = que.size();
		while (len--) {
			auto [cur_ry, cur_rx, cur_by, cur_bx] = que.front();
			que.pop();

			if (map[cur_ry][cur_rx] == 'O' && map[cur_by][cur_bx] != 'O') {
				return true;
			}

			for (int i=0; i<4; ++i) {
				int ry = cur_ry;
				int rx = cur_rx;
				int by = cur_by;
				int bx = cur_bx;

				while (1) {
					int next_ry = ry + dy[i];
					int next_rx = rx + dx[i];

					if (map[next_ry][next_rx] == '#' || map[ry][rx] == 'O')
						break;

					ry = next_ry;
					rx = next_rx;
				}

				while (1) {
					int next_by = by + dy[i];
					int next_bx = bx + dx[i];

					if (map[next_by][next_bx] == '#' || map[by][bx] == 'O')
						break;

					by = next_by;
					bx = next_bx;
				}

				if (ry == by && rx == bx) {
					if (map[by][bx] == 'O')
						continue;

					if (abs(cur_ry - ry) + abs(cur_rx - rx) > abs(cur_by - by) + abs(cur_bx - bx)) {
						ry -= dy[i];
						rx -= dx[i];
					} else {
						by -= dy[i];
						bx -= dx[i];
					}
				}

				if (visit[ry][rx][by][bx])
					continue;

				visit[ry][rx][by][bx] = 1;
				que.push({ry, rx, by, bx});
			}
		}
		if (cnt == 10)
			return false;
		cnt++;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				red = {i, j};
			} else if (map[i][j] == 'B') {
				map[i][j] = '.';
				blue = {i, j};
			}
		}
	}
	cout << bfs() << '\n';

	return 0;
}
