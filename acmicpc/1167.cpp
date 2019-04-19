#include <iostream>
#include <vector>
using namespace std;

#define MAX_VAL 100001
vector<pair<int, int>> graph[MAX_VAL];
int visit[MAX_VAL];
int n, s, e, c, d, far;

void dfs(int start, int cost)
{
	if (visit[start] == 1)
		return;

	visit[start] = 1;
	if (d < cost) {
		d = cost;
		far = start;
	}

	for (int i=0; i<graph[start].size(); ++i)
		dfs(graph[start][i].first, graph[start][i].second + cost);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &s);
		while (scanf("%d", &e) && e != -1) {
			scanf("%d", &c);
			graph[s].push_back({e, c});
		}
	}

	dfs(1, 0);
	for (int i=0; i<MAX_VAL; ++i)
		visit[i] = 0;
	dfs(far, 0);

	printf("%d\n", d);

	return 0;
}
