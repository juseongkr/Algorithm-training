#include <iostream>
#include <queue>
using namespace std;
#define MAX 251

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int r, c, sheep, wolf;
string map[MAX];
bool visit[MAX][MAX];

void bfs(int x, int y)
{
	int s = 0, w = 0;
	queue<pair<int, int>> que;

	visit[x][y] = true;
	que.push({x, y});
	if (map[x][y] == 'o')
		s++;
	else if (map[x][y] == 'v')
		w++;

	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c || visit[nx][ny] || map[nx][ny] == '#')
				continue;

			if (map[nx][ny] == 'o')
				s++;
			else if (map[nx][ny] == 'v')
				w++;

			visit[nx][ny] = true;
			que.push({nx, ny});
		}
	}
	if (s > w)
		wolf -= w;
	else
		sheep -= s;
}

int main()
{
	cin >> r >> c;
	for (int i=0; i<r; ++i) {
		cin >> map[i];
		for (int j=0; j<c; ++j) {
			if (map[i][j] == 'o')
				sheep++;
			else if (map[i][j] == 'v')
				wolf++;
		}
	}

	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			if (!visit[i][j] && (map[i][j] == 'o' || map[i][j] == 'v'))
				bfs(i, j);

	cout << sheep << " " << wolf << '\n';

	return 0;
}
