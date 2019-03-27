#include <iostream>
#include <string.h>
using namespace std;

int map[51][51];
int a[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int b[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int w, h;

void dfs(int x, int y)
{
	map[x][y] = 0;

	for (int i=0; i<8; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w)
			continue;

		if (map[next_x][next_y] == 1) {
			dfs(next_x, next_y);
		}
	}
}

int main()
{
	int cnt;
	
	while (scanf("%d %d", &w, &h) && w != 0 && h != 0) {
		cnt = 0;
		memset(map, 0, sizeof(map));

		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i=0; i<h; ++i)
			for (int j=0; j<w; ++j)
				if (map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}

		printf("%d\n", cnt);
	}

	return 0;
}
