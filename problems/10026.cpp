#include <iostream>
using namespace std;

char graph[101][101];
int visit[101][101];
int a[4] = {1, 0, -1, 0};
int b[4] = {0, 1, 0, -1};
int n, cnt = 0;

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x > n || next_y > n)
			continue;

		if (graph[next_x][next_y] == graph[x][y] && !visit[next_x][next_y])
			dfs(next_x, next_y);
	}
}

int main()
{
	string str;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		cin >> str;
		for (int j=0; j<n; ++j)
			graph[i][j] = str[j]; 
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (!visit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	printf("%d ", cnt);
	cnt = 0;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			visit[i][j] = 0;
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (!visit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
