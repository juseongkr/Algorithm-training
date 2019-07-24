#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
char map[MAX][MAX];
int visit[MAX][MAX];
pair<int, int> start, dest;
int r, c;

int main()
{
	cin >> r >> c;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'B')
				start = {i, j};
			else if (map[i][j] == 'C')
				dest = {i, j};
		}
	}

	queue<pair<int, int>> que;
	que.push({start.first, start.second});
	visit[start.first][start.second] = 1;

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			if (!visit[ny][nx] && map[ny][nx] != '*') {
				visit[ny][nx] = visit[y][x] + 1;
				que.push({ny, nx});
			}
		}
	}
	cout << visit[dest.first][dest.second] - 1 << '\n';

	return 0;
}
