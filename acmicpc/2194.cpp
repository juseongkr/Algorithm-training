#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, a, b, k, sx, sy, ex, ey, x, y;
bool map[MAX][MAX], visit[MAX][MAX];

bool check(int x, int y)
{
	for (int i=0; i<a; ++i)
		for (int j=0; j<b; ++j)
			if (map[x+i][y+j])
				return true;
	return false;
}

int main()
{
	cin >> n >> m >> a >> b >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	cin >> sx >> sy >> ex >> ey;
	sx--;
	sy--;
	ex--;
	ey--;

	queue<tuple<int, int, int>> que;
	que.push({sx, sy, 0});
	visit[sx][sy] = 1;

	while (!que.empty()) {
		auto [x, y, cnt] = que.front();
		que.pop();

		if (x == ex && y == ey) {
			cout << cnt << '\n';
			return 0;
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx + a > n || ny < 0 || ny + b > m || visit[nx][ny] || check(nx, ny))
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, cnt+1});
		}
	}
	cout << "-1\n";

	return 0;
}
