#include <iostream>
#include <climits>
#include <queue>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n, max_val = 0, min_val = INT_MAX, ans = INT_MAX;
int map[MAX][MAX], visit[MAX][MAX];

bool bfs(int val)
{
	queue<pair<int, int>> que;

	for (int k=min_val; k<=max_val; ++k) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (k <= map[i][j] && map[i][j] <= k + val)
					visit[i][j] = 0;
				else
					visit[i][j] = 1;

		que.push({0, 0});
		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			if (visit[y][x])
				continue;
			visit[y][x] = 1;

			if (y == n-1 && x == n-1)
				return true;

			for (int i=0; i<4; ++i) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= n)
					continue;

				que.push({next_y, next_x});
			}
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			max_val = max(max_val, map[i][j]);
			min_val = min(min_val, map[i][j]);
		}
	}

	int l = 0, r = max_val - min_val;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (bfs(mid)) {
			r = mid - 1;
			ans = min(ans, mid);
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
