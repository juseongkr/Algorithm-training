#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int, int> ti4;
const int INF = 1e9+7;

int n, t;
int map[MAX][MAX], dist[MAX][MAX][3];
bool visit[MAX][MAX][3];

int main()
{
	cin >> n >> t;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			for (int k=0; k<3; ++k)
				dist[i][j][k] = INF;

	priority_queue<ti4, vector<ti4>, greater<ti4>> que;
	que.push({0, 0, 0, 0});
	dist[0][0][0] = 0;

	while (!que.empty()) {
		auto [_, k, x, y] = que.top();
		que.pop();

		if (visit[x][y][k])
			continue;
		visit[x][y][k] = 1;

		for (int i=0; i<4; ++i) {
			int nd = dist[x][y][k] + t;
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = (k+1)%3;
			if (k == 2)
				nd += map[nx][ny];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (dist[nx][ny][nk] > nd) {
				dist[nx][ny][nk] = nd;
				que.push({nd, nk, nx, ny});
			}
		}
	}
	cout << min(dist[n-1][n-1][0], min(dist[n-1][n-1][1], dist[n-1][n-1][2])) << '\n';

	return 0;
}
