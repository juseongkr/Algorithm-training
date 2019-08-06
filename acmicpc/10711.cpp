#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
char map[MAX][MAX];
int visit[MAX][MAX];
int n, m;

int count(int x, int y)
{
	int cnt = 0;
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] == '.')
			cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	vector<pair<int, int>> cur;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (visit[i][j] || map[i][j] == '.')
				continue;

			if (count(i, j) >= map[i][j]-'0') {
				cur.push_back({i, j});
				visit[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while (cur.size()) {
		vector<pair<int, int>> next;

		for (int i=0; i<cur.size(); ++i)
			map[cur[i].first][cur[i].second] = '.';

		for (int i=0; i<cur.size(); ++i) {
			int x = cur[i].first;
			int y = cur[i].second;

			for (int k=0; k<8; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (visit[nx][ny] || map[nx][ny] == '.')
					continue;

				if (count(nx, ny) >= map[nx][ny]-'0') {
					next.push_back({nx, ny});
					visit[nx][ny] = 1;
				}
			}
		}
		cur = next;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}
