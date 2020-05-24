#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 51
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
typedef tuple<int, int, int, int, int> tp;

string s;
int n, m, sx, sy, cx, cy;
char map[MAX][MAX];
bool visit[MAX][MAX][4][(1 << 2)];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j) {
			map[i][j] = s[j];
			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if (map[i][j] == 'C') {
				cx = i;
				cy = j;
			}
		}
	}

	queue<tp> que;
	for (int i=0; i<4; ++i) {
		que.push({sx, sy, i, 0, 0});
		visit[sx][sy][i][0] = 1;
	}

	while (!que.empty()) {
		auto [x, y, d, b, cnt] = que.front();
		que.pop();

		if (map[x][y] == 'C') {
			if (x == cx && y == cy) {
				b |= (1 << 0);
			} else {
				b |= (1 << 1);
			}
			if (b == (1 << 2)-1) {
				cout << cnt << '\n';
				return 0;
			}
		}

		for (int i=0; i<4; ++i) {
			if (i != d) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny][i][b] || map[nx][ny] == '#')
					continue;

				visit[nx][ny][i][b] = 1;
				que.push({nx, ny, i, b, cnt+1});
			}
		}
	}
	cout << "-1\n";

	return 0;
}
