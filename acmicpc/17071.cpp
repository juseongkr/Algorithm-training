#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 500001

int main()
{
	queue<pair<int, int>> que;
	int visit[2][MAX];
	int n, k;

	cin >> n >> k;
	memset(visit, -1, sizeof(visit));
	visit[0][n] = 0;
	que.push({0, n});

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		if (0 <= y-1 && y-1 < MAX && visit[1-x][y-1] == -1) {
			visit[1-x][y-1] = visit[x][y] + 1;
			que.push({1-x, y-1});
		}

		if (0 <= y+1 && y+1 < MAX && visit[1-x][y+1] == -1) {
			visit[1-x][y+1] = visit[x][y] + 1;
			que.push({1-x, y+1});
		}

		if (0 <= y*2 && y*2 < MAX && visit[1-x][y*2] == -1) {
			visit[1-x][y*2] = visit[x][y] + 1;
			que.push({1-x, y*2});
		}
	}

	int i = 0;
	int ans = MAX;
	while (k <= MAX) {
		if (visit[i%2][k] != -1 && visit[i%2][k] <= i)
			ans = min(ans, i);
		k += ++i;
	}
	if (ans == MAX)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
