#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int graph[101][101];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n, m, k, cnt;

void dfs(int x, int y)
{
	graph[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x > m || next_y > n)
			continue;

		if (graph[next_x][next_y] == 1) {
			cnt++;
			dfs(next_x, next_y);
		}
	}
}

int main()
{
	vector<int> vec;
	int x1, x2, y1, y2;

	scanf("%d %d %d", &m, &n, &k);

	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			graph[i][j] = 1;

	for (int i=0; i<k; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int r=y1; r<y2; ++r)
			for (int c=x1; c<x2; ++c)
				graph[r][c] = 0;
	}

	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			if (graph[i][j] == 1) {
				cnt = 1;
				dfs(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());

	printf("%lu\n", vec.size());
	for (int i : vec)
		printf("%d ", i);

	return 0;
}
