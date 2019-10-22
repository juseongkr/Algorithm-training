#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, sx, sy;
int map[MAX][MAX], point[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int mid)
{
	queue<pair<int, int>> que;
	visit[sx][sy] = true;
	que.push({sx, sy});

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny])
				continue;

			if (abs(map[x][y] - map[nx][ny]) <= mid) {
				visit[nx][ny] = true;
				que.push({nx, ny});
			}
		}
	}
}

bool check(int mid)
{
	memset(visit, 0, sizeof(visit));

	bfs(mid);

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (point[i][j] && !visit[i][j])
				return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> point[i][j];
			if (point[i][j]) {
				sx = i;
				sy = j;
			}
		}
	}

	int l = 0, r = 1e9+7;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
