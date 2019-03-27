#include <iostream>
#include <vector>
using namespace std;

int map[8][8];
int tmp[8][8];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n, m;

void dfs(int x, int y)
{
	tmp[x][y] = 2;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
			continue;

		if (tmp[next_x][next_y] == 0)
			dfs(next_x, next_y);
	}
}

int main()
{
	vector<pair<int, int>> wall;
	int len, cnt, max_val = 0;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d", &map[i][j]);
			tmp[i][j] = map[i][j];
			if (map[i][j] == 0)
				wall.push_back({i, j});
		}
	}

	len = wall.size();
	for (int i=0; i<len-2; ++i) {
		for (int j=i+1; j<len-1; ++j) {
			for (int k=j+1; k<len; ++k) {
				pair<int, int> w[3] = {wall[i], wall[j], wall[k]};
				cnt = 0;

				for (int x=0; x<n; ++x)
					for (int y=0; y<m; ++y)
						tmp[x][y] = map[x][y];

				for (int x=0; x<3; ++x)
					tmp[w[x].first][w[x].second] = 1;

				for (int x=0; x<n; ++x)
					for (int y=0; y<m; ++y)
						if (tmp[x][y] == 2)
							dfs(x, y);

				for (int x=0; x<n; ++x)
					for (int y=0; y<m; ++y)
						if (tmp[x][y] == 0)
							cnt++;

				max_val = max(max_val, cnt);
			}
		}
	}

	printf("%d\n", max_val);

	return 0;
}
