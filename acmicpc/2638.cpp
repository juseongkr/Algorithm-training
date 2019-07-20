#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
bool visit[MAX][MAX];
int map[MAX][MAX];
int n, m;

void bfs()
{
	queue<pair<int, int>> que;

	visit[0][0] = true;
	que.push({0, 0});
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
				continue;

			if (!visit[next_y][next_x]) {
				if (map[next_y][next_x] != 0) {
					map[next_y][next_x]++;
				} else {
					visit[next_y][next_x] = true;
					que.push({next_y, next_x});
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int ans = 0;
	while (1) {
		memset(visit, false, sizeof(visit));
		bfs();
		int cnt = 0;
		bool flag = false;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] >= 3) {
					flag = true;
					map[i][j] = 0;
				} else if (map[i][j] == 2) {
					map[i][j] = 1;
				}
			}
		}
		if (flag)
			ans++;
		else
			break;
	}
	cout << ans;

	return 0;
}
