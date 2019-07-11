#include <iostream>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int m, n, w, b;
int visit[MAX][MAX];
char map[MAX][MAX];

int dfs(int y, int x, char c)
{
	int ret = 1;
	visit[y][x] = 1;
	for (int i=0; i<4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
			continue;

		if (!visit[next_y][next_x] && map[next_y][next_x] == c)
			ret += dfs(next_y, next_x, c);
	}
	return ret;
}

int main()
{
	cin >> m >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (visit[i][j])
				continue;
			int r = dfs(i, j, map[i][j]);
			if (map[i][j] == 'W')
				w += r * r;
			else
				b += r * r;
		}
	}
	cout << w << " " << b << '\n';

	return 0;
}
