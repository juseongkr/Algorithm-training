#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m, v;
int graph[1001][1001];
int visited[1001];

void dfs(int start)
{
	visited[start] = 1;
	printf("%d ", start);

	for (int i=1; i<=n; ++i) {
		if (visited[i] == 0 && graph[start][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int start)
{
	queue<int> que;

	visited[start] = 1;
	que.push(start);

	while (!que.empty()) {
		int p = que.front();
		que.pop();
		printf("%d ", p);

		for (int i=1; i<=n; ++i) {
			if (visited[i] == 0 && graph[p][i] == 1) {
				que.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main()
{
	int a, b;

	memset(graph, 0, sizeof(graph));
	scanf("%d %d %d", &n, &m, &v);

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}

	dfs(v);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	bfs(v);
	printf("\n");

	return 0;
}
