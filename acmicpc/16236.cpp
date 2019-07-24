#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 21

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int map[MAX][MAX], visit[MAX][MAX];
int n;

tuple<int, int, int> bfs(int y, int x, int s)
{
	memset(visit, -1, sizeof(visit));
	vector<tuple<int, int, int>> ans;
	queue<pair<int, int>> que;

	visit[y][x] = 0;
	que.push({y, x});

	while (!que.empty()) {
		auto [y, x] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (visit[ny][nx] == -1) {
				bool ok = false;
				bool eat = false;

				if (map[ny][nx] == 0)
					ok = true;
				else if (map[ny][nx] < s)
					ok = eat = true;
				else if (map[ny][nx] == s)
					ok = true;

				if (ok) {
					visit[ny][nx] = visit[y][x] + 1;
					que.push({ny, nx});
					if (eat)
						ans.push_back({visit[ny][nx], ny, nx});
				}
			}

		}
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		return ans[0];
	} else {
		return {-1, -1, -1};
	}
}

int main()
{
	pair<int, int> start;

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start = {i, j};
				map[i][j] = 0;
			}
		}
	}

	int ans = 0;
	int exp = 0;
	int size = 2;
	while (1) {
		auto [time, ny, nx] = bfs(start.first, start.second, size);
		if (time == -1)
			break;
		ans += time;
		map[ny][nx] = 0;
		exp++;
		if (exp == size) {
			size++;
			exp = 0;
		}
		start = {ny, nx};
	}
	cout << ans << '\n';

	return 0;
}
