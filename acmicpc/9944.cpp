#include <iostream>
#include <cstring>
using namespace std;
#define MAX 31
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, t, cell, ans;
bool visit[MAX][MAX];
string map[MAX];

void solve(int x, int y, int turn, int fill)
{
	if (fill == cell) {
		ans = min(ans, turn);
		return;
	}

	for (int i=0; i<4; ++i) {
		int nx = x;
		int ny = y;
		int cnt = 0;

		while (1) {
			int cx = nx + dx[i];
			int cy = ny + dy[i];

			if (cx < 0 || cx >= n || cy < 0 || cy >= m || map[cx][cy] == '*' || visit[cx][cy])
				break;

			visit[cx][cy] = 1;
			nx = cx;
			ny = cy;
			cnt++;
		}

		if (cnt)
			solve(nx, ny, turn + 1, fill + cnt);

		while (cnt--) {
			visit[nx][ny] = 0;
			nx -= dx[i];
			ny -= dy[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (cin >> n >> m) {
		++t;
		ans = INF;
		cell = 0;
		memset(visit, 0, sizeof(visit));
		for (int i=0; i<n; ++i) {
			cin >> map[i];
			for (int j=0; j<m; ++j)
				if (map[i][j] == '.')
					cell++;
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] == '.') {
					visit[i][j] = 1;
					solve(i, j, 0, 1);
					visit[i][j] = 0;
				}
			}
		}

		if (ans == INF)
			cout << "Case " << t << ": -1\n";
		else
			cout << "Case " << t << ": " << ans << '\n';
	}

	return 0;
}
