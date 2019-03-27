#include <iostream>
using namespace std;

int graph[51][51];
int visit[51], node[51];
int n, t, leaf, root;

void dfs(int s)
{
	int cnt = 0;
	visit[s] = 1;

	for (int i=0; i<n; ++i) {
		if (visit[i] == 0 && graph[s][i] != 0) {
			dfs(i);
			cnt++;
		}
	}

	if (!cnt)
		leaf++;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		node[i] = t;
		if (t != -1)
			graph[i][t] = graph[t][i] = 1;
		else
			root = i;
	}

	scanf("%d", &t);
	if (t != root) {
		graph[t][node[t]] = graph[node[t]][t] = 0;

		dfs(root);

		printf("%d\n", leaf);
	} else {
		printf("0\n");
	}
	
	return 0;
}
