#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 51

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int map[MAX][MAX], copy_map[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> active;
int n, m, ans;
bool flag;

void bfs(int left)
{
	queue<pair<int, int>> que;
	int step = 0;

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			copy_map[i][j] = map[i][j];

	for (int i=0; i<active.size(); ++i) {
		if (active[i]) {
			int x = virus[i].first;
			int y = virus[i].second;
			que.push({x, y});
			copy_map[x][y] = 3;
		}
	}
	
	while (!que.empty()) {
		int sz = que.size();
		if (left == 0) {
			flag = true;
			ans = min(ans, step);
			return;
		}

		step++;
		for (int i=0; i<sz; ++i) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			for (int j=0; j<4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (copy_map[nx][ny] == 0 || copy_map[nx][ny] == 2) {
					if (copy_map[nx][ny] == 0)
						left--;

					copy_map[nx][ny] = 3;
					que.push({nx, ny});
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ans = INT_MAX;
	int empty = 0;
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({i, j});
			if (map[i][j] == 0)
				empty++;
		}
	}
	
	sort(virus.begin(), virus.end());

	active.resize(virus.size(), 0);
	for (int i=0; i<m; ++i)
		active[i] = 1;

	sort(active.begin(), active.end());

	do {
		bfs(empty);
	} while (next_permutation(active.begin(), active.end()));

	if (flag)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
