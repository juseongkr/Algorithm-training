#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX_VAL 101
typedef tuple<int, int, int> ti3;
int map[MAX_VAL][MAX_VAL], dist[MAX_VAL][MAX_VAL], visit[MAX_VAL][MAX_VAL];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main()
{
	priority_queue<ti3, vector<ti3>, greater<ti3>> que;
	string str;
	int n, m;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> str;
		for (int j=0; j<n; ++j)
			map[i][j] = str[j]-'0';
	}

	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			dist[i][j] = INT_MAX;
			visit[i][j] = 0;
		}
	}

	dist[0][0] = 0;
	que.push({0, 0, 0});
	while (!que.empty()) {
		int cost = get<0>(que.top());
		int y = get<1>(que.top());
		int x = get<2>(que.top());
		que.pop();

		if (cost >= dist[y][x] && visit[y][x])
			continue;

		visit[y][x] = 1;
		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			int next_cost = map[next_y][next_x];

			if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n)
				continue;

			if (next_cost + cost < dist[next_y][next_x]) {
				que.push({next_cost + cost, next_y, next_x});
				dist[next_y][next_x] = next_cost + cost;
			}
		}
	}

	cout << dist[m-1][n-1] << '\n';

	return 0;
}
