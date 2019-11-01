#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int dx[10], dy[10];
bool visit[MAX][MAX];
int map[MAX][MAX];

int main()
{
	int n, m, t;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];
	cin >> t;
	for (int i=0; i<t; ++i)
		cin >> dx[i] >> dy[i];

	queue<int> que;
	for (int i=0; i<m; ++i) {
		if (map[0][i]) {
			que.push(i);
			visit[0][i] = 1;
		}
	}

	int cnt = 0;
	while (!que.empty()) {
		int sz = que.size();
		for (int i=0; i<sz; ++i) {
			int x = que.front() / 1000;
			int y = que.front() % 1000;
			que.pop();

			if (x == n-1) {
				cout << cnt << '\n';
				return 0;
			}

			for (int k=0; k<t; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || !map[nx][ny] || visit[nx][ny])
					continue;

				visit[nx][ny] = 1;
				que.push({nx*1000 + ny});
			}
		}
		cnt++;
	}
	cout << "-1\n";

	return 0;
}
