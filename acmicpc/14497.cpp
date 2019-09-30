#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 301
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s;
int n, m, x1, y1, x2, y2;
char map[MAX][MAX];
char copy_map[MAX][MAX];
bool visit[MAX][MAX];

bool bfs()
{
	queue<pair<int, int>> que;
	que.push({x1, y1});

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (!visit[nx][ny]) {
				visit[nx][ny] = 1;
				if (nx == x2 && ny == y2)
					return true;
				if (map[nx][ny] == '1') {
					copy_map[nx][ny] = '0';
					continue;
				}
				que.push({nx, ny});
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	x1--;
	y1--;
	x2--;
	y2--;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int ans = 0;
	while (1) {
		++ans;
		memset(visit, 0, sizeof(visit));
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				copy_map[i][j] = map[i][j];
		if (bfs())
			break;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				map[i][j] = copy_map[i][j];

	}
	cout << ans << '\n';

	return 0;
}
