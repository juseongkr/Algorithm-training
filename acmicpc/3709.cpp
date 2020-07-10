#include <iostream>
#include <cstring>
using namespace std;
#define MAX 52
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int T, n, r, x, y, sx, sy;
int map[MAX][MAX];

void dfs(int x, int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];

	if (nx == 0 || nx == n+1 || ny == 0 || ny == n+1) {
		cout << nx << " " << ny << '\n';
		return;
	}

	if (map[nx][ny])
		dfs(nx, ny, (d+1) % 4);
	else
		dfs(nx, ny, d);
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n >> r;
		memset(map, 0, sizeof(map));
		for (int i=0; i<r; ++i) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		cin >> sx >> sy;

		int d = 0;
		if (sx == n+1)
			d = 3;
		else if (sx == 0)
			d = 1;
		else if (sy == n+1)
			d = 2;
		else if (sy == 0)
			d = 0;

		dfs(sx, sy, d);
	}

	return 0;
}
