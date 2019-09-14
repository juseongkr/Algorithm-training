#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 450

int capa[MAX][MAX], flow[MAX][MAX], pre[MAX], visit[MAX];
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, src, sink, u, v, t;

	cin >> n >> m >> src >> sink;
	sink += n;
	for (int i=1; i<=n; ++i) {
		cin >> t;
		graph[i].push_back(i+n);
		graph[i+n].push_back(i);
		capa[i][i+n] = t;
	}

	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		graph[u+n].push_back(v);
		graph[v].push_back(u+n);
		graph[v+n].push_back(u);
		graph[u].push_back(v+n);
		capa[u+n][v] = INT_MAX;
		capa[v+n][u] = INT_MAX;
	}

	while (1) {
		queue<int> que;
		fill(pre, pre+MAX, -1);
		que.push(src);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == sink)
				break;

			for (int next=0; next<MAX; ++next) {
				if (capa[cur][next] > flow[cur][next] && pre[next] == -1) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}

		if (pre[sink] == -1)
			break;

		int min_flow = INT_MAX;
		for (int i=sink; i!=src; i=pre[i])
			min_flow = min(min_flow, capa[pre[i]][i] - flow[pre[i]][i]);

		for (int i=sink; i!=src; i=pre[i]) {
			flow[pre[i]][i] += min_flow;
			flow[i][pre[i]] -= min_flow;
		}
	}

	queue<int> que;
	visit[src] = 1;
	que.push(src);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (visit[next])
				continue;

			if (capa[cur][next] - flow[cur][next] > 0) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}
	for (int i=1; i<=n; ++i)
		if (visit[i] && !visit[i+n])
			cout << i << " ";

	return 0;
}
