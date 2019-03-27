#include <iostream>
using namespace std;

int graph[1001][1001];
int visit[1001];
int n, m, s, e, cnt = 0;

void dfs(int start)
{
	visit[start] = 1;
	for (int i=1; i<=n; ++i)
		if (visit[i] == 0 && graph[start][i] == 1)
			dfs(i);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &s, &e);
		graph[s][e] = graph[e][s] = 1;
	}

	for (int i=1; i<=n; ++i) {
		if (visit[i] == 0) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
