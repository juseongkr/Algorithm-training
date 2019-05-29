#include <iostream>
using namespace std;
#define MAX 1001

int visit[MAX][MAX];
string map[MAX];
int n, m, flag;
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};

void dfs(int y, int x)
{
	visit[y][x] = 1;
	map[y][x] = '1';
	for (int i=0; i<4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y == n-1)
			flag = 1;

		if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
			continue;

		if (!visit[next_y][next_x] && map[next_y][next_x] == '0') {
			visit[next_y][next_x] = 1;
			map[next_y][next_x] = '1';
			dfs(next_y, next_x);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<m; ++i)
		if (!visit[0][i] && map[0][i] == '0')
			dfs(0, i);

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
