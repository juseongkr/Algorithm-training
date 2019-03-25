#include <iostream>
using namespace std;

int n, m, k, r, c, cnt, max_val = 0;
int map[101][101];
int a[4] = {1, 0, -1, 0};
int b[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x > n || next_y > m)
			continue;

		if (map[next_x][next_y] == 1) {
			cnt++;
			dfs(next_x, next_y);
		}
	}
	max_val = max(max_val, cnt);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<k; ++i) {
		scanf("%d %d", &r, &c);
		map[r][c] = 1;
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (map[i][j] == 1) {
				cnt = 1;
				dfs(i, j);
			}
		}
	}

	printf("%d\n", max_val);

	return 0;
}
