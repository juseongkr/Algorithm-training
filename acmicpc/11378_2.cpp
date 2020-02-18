#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 2004
const int src = 2001, sink = 2002, pen = 2003;

int n, m, k, p, t;

class Dinic {
public:
	int len;
	vector<vector<int>> graph, c, f;
	vector<int> work, level;

	Dinic(int n) : len(n)
	{
		work.resize(n, 0);
		level.resize(n, 0);
		graph.resize(n);
		for (auto &it : graph)
			it.resize(n, 0);
		c.resize(n);
		for (auto &it : c)
			it.resize(n, 0);
		f.resize(n);
		for (auto &it : f)
			it.resize(n, 0);
	}

	void add_edge(int u, int v, int capa)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
		c[u][v] = capa;
	}

	bool bfs(int src, int sink)
	{
		for (int i=0; i<level.size(); ++i)
			level[i] = -1;
		level[src] = 0;

		queue<int> que;
		que.push(src);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (level[next] == -1 && c[cur][next] - f[cur][next] > 0) {
					level[next] = level[cur] + 1;
					que.push(next);
				}
			}
		}
		return level[sink] != -1;
	}
		
	int dfs(int cur, int dest, int flow)
	{
		if (cur == dest)
			return flow;

		for (int &i=work[cur]; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (level[next] == level[cur]+1 && c[cur][next] - f[cur][next] > 0) {
				int ret = dfs(next, dest, min(flow, c[cur][next] - f[cur][next]));
				if (ret > 0) {
					f[cur][next] += ret;
					f[next][cur] -= ret;
					return ret;
				}
			}
		}
		return 0;
	}

	int flow(int src, int sink)
	{
		int total = 0;
		while (bfs(src, sink)) {
			for (int i=0; i<work.size(); ++i)
				work[i] = 0;
			while (1) {
				int flow = dfs(src, sink, INT_MAX);
				if (flow == 0)
					break;
				total += flow;
			}
		}
		return total;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	Dinic dinic(MAX);
	for (int i=1; i<=n; ++i) {
		cin >> p;
		dinic.add_edge(src, i, 1);
		dinic.add_edge(pen, i, k);
		for (int j=0; j<p; ++j) {
			cin >> t;
			dinic.add_edge(i, 1000+t, 1);
		}
	}

	dinic.add_edge(src, pen, k);
	for (int i=1; i<=m; ++i)
		dinic.add_edge(1000+i, sink, 1);

	cout << dinic.flow(src, sink) << '\n';

	return 0;
}
