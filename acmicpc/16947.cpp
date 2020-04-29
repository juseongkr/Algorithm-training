#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 3001
const int INF = 1e9+7;

int n, x, y;
vector<int> graph[MAX];
int visit[MAX], dist[MAX];

int dfs(int cur, int prev)
{
	if (visit[cur] == 1)
		return cur;

	visit[cur] = 1;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;

		int ret = dfs(next, cur);
		if (ret == -2)
			return -2;

		if (ret >= 0) {
			visit[cur] = 2;
			return ret == cur ? -2 : ret;
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, 0);

	queue<int> que;
	for (int i=1; i<=n; ++i) {
		if (visit[i] == 2) {
			que.push(i);
			dist[i] = 1;
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (!dist[next]) {
				dist[next] = dist[cur] + 1;
				que.push(next);
			}
		}
	}

	for (int i=1; i<=n; ++i)
		cout << dist[i]-1 << " ";

	return 0;
}
