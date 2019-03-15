#include <iostream>
#include <string.h>
using namespace std;

int map[51][51];
int a[4] = {-1, 1, 0, 0};
int b[4] = {0, 0, -1, 1};
int n, m;

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];
	
		if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
			continue;

		if (map[next_x][next_y] == 1)
			dfs(next_x, next_y);
	}
}

int main()
{
	int num, k, x, y, cnt;
	
	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		cnt = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d %d", &m, &n, &k);

		for (int j=0; j<k; ++j) {
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
	
		for (int a=0; a<m; a++) {
			for (int b=0; b<n; ++b) {
				if (map[a][b] == 1) {
					dfs(a, b);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
