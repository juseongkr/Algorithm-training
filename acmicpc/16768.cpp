#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define M 10

vector<pair<int, int>> hist;
string map[1001];
int visit[1001][10];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int cnt, flag;
int N, K;

void bfs(int a, int b, char c)
{
	memset(visit, 0, sizeof(visit));

	queue<pair<int, int>> que;
	hist.push_back({a, b});
	que.push({a, b});
	visit[a][b] = 1;

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)
				continue;

			if (!visit[next_y][next_x] && map[next_y][next_x] == c) {
				hist.push_back({next_y, next_x});
				que.push({next_y, next_x});
				visit[next_y][next_x] = 1;
				cnt++;
			}
		}
	}
}

void gravity()
{
	for (int i=0; i<M; ++i) {
		queue<char> que;
		int k = 0;
		for (int j=N-1; j>=0; j--) {
			if (map[j][i] != '0') {
				que.push(map[j][i]);
				map[j][i] = '0';
			}
		}
		while (!que.empty()) {
			map[N-1-k][i] = que.front();
			que.pop();
			k++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i=0; i<N; ++i)
		cin >> map[i];

	while (1) {
		flag = 0;
		gravity();
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				if (map[i][j] != '0') {
					cnt = 1;
					hist.clear();
					bfs(i, j, map[i][j]);
					if (cnt >= K) {
						flag = 1;
						for (int k=0; k<hist.size(); ++k)
							map[hist[k].first][hist[k].second] = '0';
					}
				}
			}
		}
		if (!flag)
			break;
	}

	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j)
			cout << map[i][j];
		cout << '\n';
	}

	return 0;
}
