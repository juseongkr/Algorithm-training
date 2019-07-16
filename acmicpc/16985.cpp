#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

const int dy[6] = {1, -1, 0, 0, 0, 0};
const int dx[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
int maze[5][5][5], maze_cpy[5][5][5], step[5][5][5];
int order[5] = {0, 1, 2, 3, 4};
int ans = INT_MAX;
bool flag;

void bfs()
{
	queue<tuple<int, int, int>> que;
	que.push({0, 0, 0});
	memset(step, -1, sizeof(step));
	step[0][0][0] = 0;

	while (!que.empty()) {
		auto [y, x, z] = que.front();
		que.pop();

		if (y == 4 && x == 4 && z == 4) {
			ans = min(ans, step[y][x][z]);
			if (ans == 12) {
				flag = true;
				return;
			}
			return;
		}

		for (int i=0; i<6; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			int next_z = z + dz[i];

			if (next_y < 0 || next_x < 0 || next_z < 0 || next_y >= 5 || next_x >= 5 || next_z >= 5)
				continue;

			if (step[next_y][next_x][next_z] == -1 && maze_cpy[next_y][next_x][next_z]) {
				step[next_y][next_x][next_z] = step[y][x][z] + 1;
				que.push({next_y, next_x, next_z});
			}
		}
	}
}

void turn(int k)
{
	int t[5][5];
	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j)
			t[j][4-i] = maze_cpy[k][i][j];

	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j)
			maze_cpy[k][i][j] = t[i][j];
}

int main()
{
	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j)
			for (int k=0; k<5; ++k)
				cin >> maze[i][j][k];

	do {
		for (int i=0; i<5; ++i)
			for (int j=0; j<5; ++j)
				for (int k=0; k<5; ++k)
					maze_cpy[order[i]][j][k] = maze[i][j][k];

		for (int i=0; i<4; ++i) {
			turn(0);
			if (maze_cpy[0][0][0]) {
				for (int j=0; j<4; ++j) {
					turn(1);
					for (int k=0; k<4; ++k) {
						turn(2);
						for (int x=0; x<4; ++x) {
							turn(3);
							for (int y=0; y<4; ++y) {
								turn(4);
								if (maze_cpy[4][4][4])
									bfs();
								if (flag) {
									cout << "12\n";
									return 0;
								}
							}
						}
					}
				}
			}
		}
	} while (next_permutation(order, order + 5));

	if (ans == INT_MAX)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
