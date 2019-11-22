#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, x, y, a, b;
vector<pair<int, int>> graph[MAX][MAX];
bool visit[MAX][MAX], light[MAX][MAX];

bool check(int x, int y)
{
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n && visit[nx][ny])
			return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> a >> b;
		graph[x][y].push_back({a, b});
	}

	queue<pair<int, int>> que;
	que.push({1, 1});
	visit[1][1] = light[1][1] = 1;

	int cnt = 0;
	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<graph[x][y].size(); ++i) {
			auto [nx, ny] = graph[x][y][i];

			if (visit[nx][ny] || light[nx][ny])
				continue;

			light[nx][ny] = 1;
			cnt++;

			if (check(nx, ny)) {
				visit[nx][ny] = 1;
				que.push({nx, ny});
			}
		}

		for (int k=0; k<4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] || !light[nx][ny])
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny});
		}
	}
	cout << cnt+1 << '\n';

	return 0;
}
