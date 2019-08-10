#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
#define MAX 51

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int map[MAX][MAX], dist[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> active;
int n, m, ans;
bool flag;

void bfs(int left)
{
	queue<pair<int, int>> que;
	int step, cnt = 0;

	for (int i=0; i<active.size(); ++i) {
		if (active[i]) {
			int x = virus[i].first;
			int y = virus[i].second;
			que.push({x, y});
			dist[x][y] = 0;
		}
	}

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		step = dist[x][y];
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (map[nx][ny] != 1 && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				que.push({nx, ny});
				cnt++;
			}
		}
	}
	if (left == cnt) {
		flag = true;
		ans = min(ans, step);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ans = INT_MAX;
	cin >> n >> m;
	int empty = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({i, j});
			if (map[i][j] == 0)
				empty++;
		}
	}
	empty += virus.size() - m;
	
	sort(virus.begin(), virus.end());

	active.resize(virus.size(), 0);
	for (int i=0; i<m; ++i)
		active[i] = 1;

	sort(active.begin(), active.end());

	do {
		memset(dist, -1, sizeof(dist));
		bfs(empty);
	} while (next_permutation(active.begin(), active.end()));

	if (flag)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
