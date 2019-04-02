#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[501];
int visit[501];
int n, m, vertex;

int dfs(int s)
{
	int edge = 0;
	visit[s] = 1;
	for (int i=0; i<graph[s].size(); ++i) {
		if (visit[graph[s][i]] == 0)
			edge += dfs(graph[s][i]);
	}
	vertex += graph[s].size();
	return edge + 1;
}

int main()
{
	int a, b, tree, c = 1;

	while (scanf("%d %d", &n, &m), (n || m)) {
		tree = 0;
		for (int i=0; i<501; ++i) {
			visit[i] = 0;
			graph[i].clear();
		}
	
		for (int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i=1; i<=n; ++i) {
			vertex = 0;
			if (visit[i] == 0) {
				if (dfs(i) - 1 == vertex / 2)
					tree++;
			}
		}

		if (tree == 0)
			printf("Case %d: No trees.\n", c++);
		else if (tree == 1)
			printf("Case %d: There is one tree.\n", c++);
		else
			printf("Case %d: A forest of %d trees.\n", c++, tree);
	}
	return 0;
}
