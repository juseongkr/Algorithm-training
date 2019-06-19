#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
queue<pii> que, danger;
int visit[MAX][MAX];
string map[MAX];
pii start;
int r, c;

int bfs()
{
	int len, ret = 0;
	while (!que.empty()) {
		len = danger.size();
		for (int k=0; k<len; ++k) {
			int y = danger.front().first;
			int x = danger.front().second;
			danger.pop();

			for (int i=0; i<4; ++i) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (next_y < 0 || next_x < 0 || next_y >= r || next_x >= c)
					continue;

				if (map[next_y][next_x] == '.' || map[next_y][next_x] == 'J') {
					map[next_y][next_x] = 'F';
					danger.push({next_y, next_x});
				}
			}
		}

		len = que.size();
		for (int k=0; k<len; ++k) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			if (y == 0 || y == r-1 || x == 0 || x == c-1)
				return ret;

			for (int i=0; i<4; ++i) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (next_y < 0 || next_x < 0 || next_y >= r || next_x >= c)
					continue;

				if (!visit[next_y][next_x] && map[next_y][next_x] == '.') {
					visit[next_y][next_x] = 1;
					que.push({next_y, next_x});
				}
			}
		}
		ret++;
	}
	return -1;
}

int main()
{
	cin >> r >> c;
	for (int i=0; i<r; ++i) {
		cin >> map[i];
		for (int j=0; j<c; ++j) {
			if (map[i][j] == 'J')
				que.push({i, j});
			else if (map[i][j] == 'F')
				danger.push({i, j});
		}
	}

	int ans = bfs();
	if (ans != -1)
		cout << ans+1 << '\n';
	else
		cout << "IMPOSSIBLE\n";

	return 0;
}
