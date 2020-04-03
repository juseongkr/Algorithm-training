#include <iostream>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
int visit[MAX][MAX];
int map[MAX][MAX];
string s;

int dfs(int x, int y, int k)
{
	if (visit[x][y])
		return visit[x][y];
	visit[x][y] = k;

	int d = map[x][y];
	int nx = x + dx[d];
	int ny = y + dy[d];
	return visit[x][y] = dfs(nx, ny, k);
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j) {
			if (s[j] == 'R')
				map[i][j] = 0;
			else if (s[j] == 'D')
				map[i][j] = 1;
			else if (s[j] == 'L')
				map[i][j] = 2;
			else
				map[i][j] = 3;
		}
	}

	int cnt = 1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int ret = dfs(i, j, cnt);
			if (ret == cnt)
				cnt++;
		}
	}
	cout << cnt-1 << '\n';

	return 0;
}
