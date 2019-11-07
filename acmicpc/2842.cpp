#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 51
const int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dyy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, k, sx, sy;
char map[MAX][MAX];
int t[MAX][MAX];
bool visit[MAX][MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				sx = i;
				sy = j;
			} else if (map[i][j] == 'K') {
				k++;
			}
		}
	}

	vector<int> vec;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> t[i][j];
			vec.push_back(t[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	int l = 0, r = 0, ans = 1e9+7;
	while (l < vec.size()) {
		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> que;

		if (vec[l] <= t[sx][sy] && t[sx][sy] <= vec[r]) {
			visit[sx][sy] = true;
			que.push({sx, sy});
		}

		int cnt = 0;
		while (!que.empty()) {
			auto [x, y] = que.front();
			que.pop();

			for (int i=0; i<8; ++i) {
				int nx = x + dxx[i];
				int ny = y + dyy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny])
					continue;

				if (vec[l] <= t[nx][ny] && t[nx][ny] <= vec[r]) {
					visit[nx][ny] = true;
					que.push({nx, ny});
					if (map[nx][ny] == 'K')
						cnt++;
				}
			}
		}
		if (cnt == k) {
			ans = min(ans, vec[r] - vec[l]);
			l++;
		} else if (r < vec.size()-1) {
			r++;
		} else {
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
