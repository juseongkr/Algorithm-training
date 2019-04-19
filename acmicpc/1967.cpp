#include <iostream>
#include <vector>
using namespace std;

#define MAX_VAL 10001
int visit[MAX_VAL];
vector<pair<int, int>> graph[MAX_VAL];
int n, a, b, c, far, max_val;

void dfs(int start, int cost)
{
	if (visit[start] == 1)
		return;

	visit[start] = 1;
	if (max_val < cost) {
		max_val = cost;
		far = start;
	}

	for (int i=0; i<graph[start].size(); ++i)
		dfs(graph[start][i].first, graph[start][i].second + cost);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n-1; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dfs(1, 0);
	for (int i=0; i<MAX_VAL; ++i)
		visit[i] = 0;
	dfs(far, 0);

	printf("%d\n", max_val);

	return 0;
}
