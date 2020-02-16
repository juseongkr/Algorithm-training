#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 2004
const int src = 2001, sink = 2002, pen = 2003;

int c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> graph[MAX];
int n, m, k, p, t;

void add_edge(int u, int v, int capa)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
	c[u][v] = capa;
}

int flow(int src, int sink)
{
	int total = 0;
	while (1) {
		fill(pre, pre+MAX, -1);
		queue<int> que;
		que.push(src);

		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == sink)
				break;
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (pre[next] == -1 && c[cur][next] > f[cur][next]) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}
		if (pre[sink] == -1)
			break;

		int min_val = INT_MAX;
		for (int i=sink; i!=src; i=pre[i])
			min_val = min(min_val, c[pre[i]][i] - f[pre[i]][i]);

		for (int i=sink; i!=src; i=pre[i]) {
			f[pre[i]][i] += min_val;
			f[i][pre[i]] -= min_val;
		}
		total += min_val;
	}
	return total;
}

int main()
{
	cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) {
		cin >> p;
		add_edge(src, i, 1);
		add_edge(pen, i, k);
		for (int j=0; j<p; ++j) {
			cin >> t;
			add_edge(i, 1000+t, 1);
		}
	}

	add_edge(src, pen, k);
	for (int i=1; i<=m; ++i)
		add_edge(1000+i, sink, 1);

	cout << flow(src, sink) << '\n';

	return 0;
}
