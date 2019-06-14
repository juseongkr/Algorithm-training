#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 51

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
queue<tuple<int, int, int>> que;
int w, h, num, start_y, start_x, step;
int visit[MAX][MAX][MAX];
string map[MAX];

int main()
{
	cin >> w >> h;
	for (int i=0; i<h; ++i) {
		cin >> map[i];
		for (int j=0; j<w; ++j) {
			if (map[i][j] == 'X') {
				map[i][j] = num+'0';
				num++;
			} else if (map[i][j] == 'S') {
				start_y = i;
				start_x = j;
			}
		}
	}

	que.push({start_y, start_x, 0});
	visit[start_y][start_x][0] = 1;
	while (!que.empty()) {
		int t = que.size();
		while (t--) {
			auto [y, x, k] = que.front();
			que.pop();

			if (k+1 == (1 << num) && map[y][x] == 'E') {
				cout << step << '\n';
				return 0;
			}

			for (int i=0; i<4; ++i) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];
				int next_k = k;

				if (next_y < 0 || next_x < 0 || next_y >= h || next_x >= w)
					continue;

				if ('0' <= map[next_y][next_x] && map[next_y][next_x] <= '9')
					next_k = k | (1 << (map[next_y][next_x]-'0'));

				if (map[next_y][next_x] != '#' && !visit[next_y][next_x][next_k]) {
					que.push({next_y, next_x, next_k});
					visit[next_y][next_x][next_k] = 1;
				}
			}
		}
		step++;
	}

	return 0;
}
