#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
pair<int, int> start, dest;
int step[MAX][MAX];
char map[MAX][MAX];
bool check = true;
int w, h;

int main()
{
	queue<pair<int, int>> que;

	cin >> w >> h;
	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (check) {
					que.push({i, j});
					check = false;
				} else {
					dest = {i, j};
				}
			}
		}
	}

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			while (1) {
				if (next_y < 0 || next_x < 0 || next_y >= h || next_x >= w || map[next_y][next_x] == '*')
					break;

				if (!step[next_y][next_x]) {
					step[next_y][next_x] = step[y][x] + 1;
					que.push({next_y, next_x});
				}

				next_y += dy[i];
				next_x += dx[i];
			}
		}
	}

	cout << step[dest.first][dest.second] - 1 << '\n';

	return 0;
}
