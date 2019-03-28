#include <iostream>
using namespace std;

int map[101][101];
int tmp[101][101];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n;

void dfs(int x, int y, int k)
{
	tmp[x][y] = -1;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
			continue;

		if (tmp[next_x][next_y] >= k)
			dfs(next_x, next_y, k);
	}
}

int main()
{
	int cnt, max_cnt = 0, ans = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", &map[i][j]);
			tmp[i][j] = map[i][j];
			max_cnt = max(max_cnt, map[i][j]);
		}
	}

	for (int k=0; k<=max_cnt; ++k) {
		cnt = 0;

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				tmp[i][j] = map[i][j];

		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (tmp[i][j] >= k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);

	return 0;
}
