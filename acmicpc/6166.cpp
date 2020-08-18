#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 302
const int INF = 1e4+1;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int> tp;

int m, x, y, t;
bool visit[MAX][MAX];
int field[MAX][MAX];

int bfs(int x, int y)
{
	queue<tp> que;
	que.push({x, y, 0});
	visit[x][y] = 1;

	while (!que.empty()) {
		auto [x, y, t] = que.front();
		que.pop();

		if (field[x][y] == INF)
			return t;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || visit[nx][ny])
				continue;

			if (t+1 < field[nx][ny]) {
				visit[nx][ny] = 1;
				que.push({nx, ny, t+1});
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m;
	for (int i=0; i<MAX; ++i)
		fill(field[i], field[i]+MAX, INF);

	while (m--) {
		cin >> x >> y >> t;
		field[x][y] = min(field[x][y], t);

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
				continue;

			field[nx][ny] = min(field[nx][ny], t);
		}
	}

	cout << bfs(0, 0) << '\n';

	return 0;
}
