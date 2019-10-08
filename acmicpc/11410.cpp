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

int a[51][51];

int main()
{
	int n, p, t;

	cin >> n >> p;
	MCMF mm = MCMF(2*n+1);
	int src = 2*n+1, sink = 2*n+2;
	int start = 0, end = 2*n-1;
	for (int i=0; i<n-1; ++i)
		for (int j=i+1; j<n; ++j)
			cin >> a[i][j];

	for (int i=0; i<n; ++i)
		mm.add_edge(i, i+n, p, 0);

	mm.add_edge(src, start, INT_MAX, 0);
	mm.add_edge(end, sink, INT_MAX, 0);

	for (int i=0; i<n-1; ++i) {
		for (int j=i+1; j<n; ++j) {
			cin >> t;
			mm.add_edge(i+n, j, a[i][j], -t);
			mm.add_edge(i+n, j, p, 0);
		}
	}
	cout << -mm.mcmf(src, sink).first << '\n';

	return 0;
}
