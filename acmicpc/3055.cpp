#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> que, water;
pair<int, int> start, dest;
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
int step[51][51];
string map[51];
int n, m, ans;

void bfs()
{
	que.push(start);
	step[start.first][start.second] = 1;

	while (!que.empty()) {
		for (int i=0; i<water.size(); ++i) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int j=0; j<4; ++j) {
				int next_x = x + a[j];
				int next_y = y + b[j];

				if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
					continue;

				if (map[next_x][next_y] == '.') {
					map[next_x][next_y] = '*';
					water.push({next_x, next_y});
				}
			}
		}

		for (int i=0; i<que.size(); ++i) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if (x == dest.first && y == dest.second)
				return;

			for (int j=0; j<4; ++j) {
				int next_x = x + a[j];
				int next_y = y + b[j];

				if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m)
					continue;

				if (step[next_x][next_y] == 0 &&
				    map[next_x][next_y] != '*' &&
				    map[next_x][next_y] != 'X') {
					step[next_x][next_y] = step[x][y] + 1;
					que.push({next_x, next_y});
				}
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'S')
				start = {i, j};
			else if (map[i][j] == 'D')
				dest = {i, j};
			else if (map[i][j] == '*')
				water.push({i, j});
		}
	}
	
	bfs();

	ans = step[dest.first][dest.second];

	if (ans)
		cout << ans-1 << '\n';
	else
		cout << "KAKTUS\n";

	return 0;
}
