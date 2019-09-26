#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class MCMF {
public:
	struct Edge {
		int v, c, d, rev;
		Edge() { }
		Edge(int x, int y, int z, int r) : v(x), rev(y), c(z), d(r) { }
	};
	int len;
	vector<vector<Edge>> graph;

	MCMF(int n) : len(n+2)
	{
		graph.resize(len);
	}

	// return cost, flow
	pair<int, int> mcmf(int src, int sink)
	{
		int min_cost = 0, max_flow = 0;
		vector<int> dist(len), prev(len), previdx(len);
		vector<bool> inque(len);

		while (1) {
			for (int i=0; i<len; ++i) {
				dist[i] = INT_MAX;
				prev[i] = previdx[i] = -1;
			}

			queue<int> que;
			inque[src] = true;
			dist[src] = 0;
			que.push(src);

			while (!que.empty()) {
				int cur = que.front();
				que.pop();
				inque[cur] = false;

				for (int i=0; i<graph[cur].size(); ++i) {
					int next = graph[cur][i].v;
					if (graph[cur][i].c && dist[next] > dist[cur] + graph[cur][i].d) {
						dist[next] = dist[cur] + graph[cur][i].d;
						prev[next] = cur;
						previdx[next] = i;
						if (!inque[next]) {
							inque[next] = true;
							que.push(next);
						}
					}
				}
			}
			if (prev[sink] == -1)
				break;

			int flow = INT_MAX;
			for (int i=sink; i!=src; i=prev[i])
				flow = min(flow, graph[prev[i]][previdx[i]].c);

			for (int i=sink; i!=src; i=prev[i]) {
				graph[prev[i]][previdx[i]].c -= flow;
				graph[i][graph[prev[i]][previdx[i]].rev].c += flow;
				min_cost += flow * graph[prev[i]][previdx[i]].d;
			}
			max_flow += flow;
		}
		return {min_cost, max_flow};
	}

	void add_edge(int u, int v, int c, int d)
	{
		graph[u].push_back(Edge(v, graph[v].size(), c, d));
		graph[v].push_back(Edge(u, graph[u].size()-1, 0, -d));
	}
};

int in(int x) { return 2*x; }
int out(int x) { return 2*x+1; }

int main()
{
	int n, m, u, v, c;

	while (cin >> n >> m) {
		MCMF mm = MCMF(2*n+2);
		int src = in(n+1), sink = out(n+1);

		mm.add_edge(src, in(1), 2, 0);
		mm.add_edge(out(n), sink, 2, 0);
		for (int i=0; i<m; ++i) {
			cin >> u >> v >> c;
			mm.add_edge(out(u), in(v), 1, c);
		}
		for (int i=1; i<=n; ++i) {
			if (i == 1 || i == n)
				mm.add_edge(in(i), out(i), 2, 0);
			else
				mm.add_edge(in(i), out(i), 1, 0);
		}
		cout << mm.mcmf(src, sink).first << '\n';
	}

	return 0;
}
