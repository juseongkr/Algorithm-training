#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define N 201
#define D 101
#define MAX N+D+2
const int src = MAX-1, sink = MAX-2;

int n, k, d, p, t;

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
	cin >> n >> k >> d;
	Dinic f(MAX);
	for (int i=0; i<d; ++i) {
		cin >> p;
		f.add_edge(i+N, sink, p);
	}

	for (int i=0; i<n; ++i) {
		cin >> t;
		for (int j=0; j<t; ++j) {
			cin >> p;
			p--;
			f.add_edge(i, p+N, 1);
		}
		f.add_edge(src, i, k);
	}

	cout << f.flow(src, sink) << '\n';

	return 0;
}
