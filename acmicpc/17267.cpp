#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int, int> ti;

int n, m, L, R;
string map[MAX];
bool visit[MAX][MAX];
queue<ti> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> L >> R;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '2') {
				que.push({i, j, L, R});
				visit[i][j] = 1;
			} else if (map[i][j] == '1') {
				visit[i][j] = 1;
			}
		}
	}

	int ans = 1;
	while (!que.empty()) {
		auto [x, y, l, r] = que.front();
		que.pop();

		for (int nx=x-1; nx>=0; nx--) {
			if (!visit[nx][y]) {
				visit[nx][y] = 1;
				que.push({nx, y, l, r});
				ans++;
			} else {
				break;
			}
		}

		for (int nx=x+1; nx<n; ++nx) {
			if (!visit[nx][y]) {
				visit[nx][y] = 1;
				que.push({nx, y, l, r});
				ans++;
			} else {
				break;
			}
		}

		if (0 < y && 0 < l) {
			if (!visit[x][y-1]) {
				visit[x][y-1] = 1;
				que.push({x, y-1, l-1, r});
				ans++;
			}
		}

		if (y < m-1 && 0 < r) {
			if (!visit[x][y+1]) {
				visit[x][y+1] = 1;
				que.push({x, y+1, l, r-1});
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
