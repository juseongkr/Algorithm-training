#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
const int INF = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX][2];

bool check(int k)
{
	memset(visit, 0, sizeof(visit));
	queue<tuple<int, int, bool>> que;

	if (k >= map[0][0]) {
		visit[0][0][0] = 1;
		que.push({0, 0, false});
	}

	while (!que.empty()) {
		auto [x, y, f] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (k >= map[nx][ny] && !visit[nx][ny][f]) {
				visit[nx][ny][f] = true;
				que.push({nx, ny, f});

			} else if (!f) {
				int nxx = nx + dx[i];
				int nyy = ny + dy[i];

				if (nxx < 0 || nxx >= n || nyy < 0 || nyy >= m)
					continue;

				if (k >= map[nxx][nyy] && !visit[nxx][nyy][1]) {
					visit[nxx][nyy][1] = true;
					que.push({nxx, nyy, true});
				}
			}

		}
	}
	return (visit[n-1][m-1][0] || visit[n-1][m-1][1]);
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int l = 0, r = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << r+1 << '\n';

	return 0;
}
