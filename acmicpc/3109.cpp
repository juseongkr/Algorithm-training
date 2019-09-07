#include <iostream>
using namespace std;
#define MAX 10001
const int dx[3] = {-1, 0, 1};
const int dy[3] = {1, 1, 1};

int n, m, ans;
string map[MAX];
bool visit[MAX][501];

bool dfs(int x, int y)
{
	if (y == m-1)
		return true;

	for (int i=0; i<3; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (!visit[nx][ny] && map[nx][ny] == '.') {
			visit[nx][ny] = 1;
			if (dfs(nx, ny))
				return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i) {
		visit[i][0] = 1;
		ans += dfs(i, 0);
	}
	cout << ans << '\n';

	return 0;
}
