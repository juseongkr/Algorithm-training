#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, k, r, x, y, a, b;
set<pair<int, int>> graph[MAX][MAX];
pair<int, int> cow[MAX];
bool visit[MAX][MAX];

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > n || ny < 1 || ny > n)
			continue;

		if (visit[nx][ny] || graph[x][y].count({nx, ny}))
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	cin >> n >> k >> r;
	for (int i=0; i<r; ++i) {
		cin >> x >> y >> a >> b;
		graph[x][y].insert({a, b});
		graph[a][b].insert({x, y});
	}

	for (int i=0; i<k; ++i)
		cin >> cow[i].first >> cow[i].second;

	int ans = 0;
	for (int i=0; i<k; ++i) {
		memset(visit, 0, sizeof(visit));
		auto [x, y] = cow[i];
		dfs(x, y);
		for (int j=i+1; j<k; ++j) {
			auto [u, v] = cow[j];
			if (!visit[u][v])
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
