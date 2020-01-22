#include <iostream>
using namespace std;
#define MAX 2001
#define BIAS 500
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, x1, x2, y1, y2, ans;
bool visit[MAX][MAX];
int map[MAX][MAX];

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
			continue;

		if (!visit[nx][ny] && map[nx][ny]) {
			visit[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;

		x1 = (x1 + BIAS) * 2;
		x2 = (x2 + BIAS) * 2;
		y1 = (y1 + BIAS) * 2;
		y2 = (y2 + BIAS) * 2;

		for (int x=x1; x<=x2; ++x)
			map[x][y1] = map[x][y2] = 1;

		for (int y=y1; y<=y2; ++y)
			map[x1][y] = map[x2][y] = 1;
	}

	for (int i=0; i<MAX; ++i) {
		for (int j=0; j<MAX; ++j) {
			if (map[i][j] && !visit[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}

	if (visit[BIAS*2][BIAS*2])
		ans--;

	cout << ans << '\n';

	return 0;
}
