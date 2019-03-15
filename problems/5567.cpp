#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int graph[501][501];
int visit[501];
int n, m, cnt = 0;

int bfs(int start, int depth)
{
	queue<pair<int, int>> que;

	visit[start] = 1;
	que.push({start, depth});

	while (!que.empty()) {
		int num = que.front().first;
		int dep = que.front().second;
		que.pop();

		if (dep <= 2)
			cnt++;

		for (int i=1; i<=n; ++i) {
			if (visit[i] == 0 && graph[num][i] == 1) {
				que.push({i, dep+1});
				visit[i] = 1;
			}
		}
	}

	return cnt;
}

int main()
{
	int a, b;

	scanf("%d %d", &n, &m);
	memset(graph, 0, sizeof(graph));

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}

	printf("%d\n", bfs(1, 0) - 1);

	return 0;
}
