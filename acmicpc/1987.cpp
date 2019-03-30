#include <iostream>
using namespace std;

char s[22][22];
int visit[26];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int n, m, cnt = 0;

void dfs(int x, int y, int c)
{
	cnt = max(cnt, c);
	if (cnt > 25)
		return;

	visit[s[x][y] - 'A'] = 1;

	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (visit[s[next_x][next_y] - 'A'] == 0 && s[next_x][next_y])
			dfs(next_x, next_y, c+1);
	}
	visit[s[x][y] - 'A'] = 0;
}

int main()
{
	string t;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		cin >> t;
		for (int j=0; j<m; ++j)
			s[i][j] = t[j];
	}

	dfs(0, 0, 1);

	printf("%d\n", cnt);

	return 0;
}
