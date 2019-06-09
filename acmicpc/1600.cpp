#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 201

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};
const int hy[8] = {-1, -2, -2, -1, 2, 1, 2, 1};
const int hx[8] = {-2, -1, 1, 2, 1, 2, -1, -2};
int map[MAX][MAX], visit[31][MAX][MAX];
int k, w, h;

int bfs()
{
	queue<tuple<int, int, int, int>> que;
	que.push({0, 0, 0, 0});
	visit[0][0][0] = 1;

	while (!que.empty()) {
		auto [cur_y, cur_x, cur_k, step] = que.front();
		que.pop();

		if (cur_y == h-1 && cur_x == w-1)
			return step;

		if (cur_k < k) {
			for (int i=0; i<8; ++i) {
				int next_y = cur_y + hy[i];
				int next_x = cur_x + hx[i];

				if (next_y < 0 || next_x < 0 || next_y >= h || next_x >= w)
					continue;

				if (!visit[cur_k+1][next_y][next_x] && !map[next_y][next_x]) {
					visit[cur_k+1][next_y][next_x] = 1;
					que.push({next_y, next_x, cur_k+1, step+1});
				}
			}
		}
		for (int i=0; i<4; ++i) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= h || next_x >= w)
				continue;

			if (!visit[cur_k][next_y][next_x] && !map[next_y][next_x]) {
				visit[cur_k][next_y][next_x] = 1;
				que.push({next_y, next_x, cur_k, step+1});
			}
		}
	}
	return -1;
}

int main()
{
	cin >> k >> w >> h;
	for (int i=0; i<h; ++i)
		for (int j=0; j<w; ++j)
			cin >> map[i][j];

	cout << bfs() << '\n';

	return 0;
}
