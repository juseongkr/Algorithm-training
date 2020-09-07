#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, label, cnt;
int map[MAX][MAX], visit[MAX][MAX];
unordered_map<int, int> sz;

void dfs(int x, int y)
{
	visit[x][y] = label;
	sz[label] = max(sz[label], ++cnt);

	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || !map[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] && !visit[i][j]) {
				cnt = 0;
				label++;
				dfs(i, j);
			}
		}
	}

	int ans = 0;
	vector<bool> check(label+1, 0);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j])
				continue;

			int temp = 0;
			for (int d=0; d<4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				int lb = visit[nx][ny];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[lb])
					continue;

				temp += sz[lb];
				check[lb] = 1;
			}

			ans = max(ans, temp + 1);

			for (int d=0; d<4; ++d) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				int lb = visit[nx][ny];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				check[lb] = 0;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
