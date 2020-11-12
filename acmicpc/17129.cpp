#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 3001
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, sx, sy;
string map[MAX];
bool visit[MAX][MAX];
queue<tuple<int, int, int>> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j)
			if (map[i][j] == '2')
				que.push({i, j, 0});
	}

	while (!que.empty()) {
		auto [x, y, cnt] = que.front();
		que.pop();

		if (map[x][y] >= '3') {
			cout << "TAK\n" << cnt << '\n';
			return 0;
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || map[nx][ny] == '1')
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, cnt+1});
		}
	}

	cout << "NIE\n";

	return 0;
}
