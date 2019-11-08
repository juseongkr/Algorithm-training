#include <iostream>
using namespace std;
#define MAX 11
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int map[MAX][MAX];
bool visit[MAX][MAX];
int ans = 1e9+7;
int n;

void solve(int cnt, int sum)
{
	if (cnt == 3) {
		ans = min(ans, sum);
		return;
	}

	for (int i=1; i<n-1; ++i) {
		for (int j=1; j<n-1; ++j) {
			if (visit[i][j])
				continue;

			bool flag = false;
			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny]) {
					flag = true;
					break;
				}
			}
			if (flag)
				continue;

			int ret = map[i][j];
			visit[i][j] = 1;
			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				ret += map[nx][ny];
				visit[nx][ny] = 1;
			}

			solve(cnt+1, sum+ret);

			visit[i][j] = 0;
			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				visit[nx][ny] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	solve(0, 0);

	cout << ans << '\n';

	return 0;
}
